import lejos.nxt.Motor;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.UltrasonicSensor;
import lejos.nxt.LightSensor;
import lejos.nxt.SensorPort;
import lejos.nxt.Button;
import lejos.nxt.Sound;
import lejos.nxt.TouchSensor;
import lejos.util.Delay;

import java.util.Random;
import java.util.ArrayList;
import java.lang.Math;

import missionthree.util.ObstacleDetector;

/**
 * MISSION 3: Work in progress.
 */
public class MissionThree
{   
    /**
     * The light sensor.
     */
    private LightSensor lightSensor;
	
	/**
	 * The ultrasonic sensor.
	 */
	private final UltrasonicSensor ultrasonicSensor;
	
	/**
	 * The touch sensor.
	 */
	private TouchSensor touchSensor;
    
    /**
	 * The port for the ultrasonic sensor is set to Port 1.
	 */
    private final SensorPort ultrasonicSensorPort = SensorPort.S1;
	
    /**
     * The port for the light sensor is set to Port 4.
     */
    private final SensorPort lightSensorPort = SensorPort.S4;
	
	/**
	 * The port for the touch sensor is set to Port 3.
	 */
	 private final SensorPort touchSensorPort = SensorPort.S3;
	 
	 /**
	  * The port for the light sensor (pointing down) is set to Port 2.
	  */
	 private final SensorPort lightSensorDownPort = SensorPort.S2;
	 
	 /**
	  * The light sensor (pointing down).
	  */
	 private final LightSensor lightSensorDown;
    
	/**
	 * The differential pilot.
	 */
    private final DifferentialPilot pilot;
	
    /**
	 * Right motor set to Motor A.
	 */
    private final RegulatedMotor rightMotor = Motor.A;
    
	/**
	 * Left motor set to Motor C.
	 */
    private final RegulatedMotor leftMotor = Motor.C;
    
    /**
     * The wheel diameter of each of the robot's wheels written on the side of
     * the tire in millimetres.
     */
    private final float WHEEL_DIAMETER = 55.0f;
    
    /**
     * The track width of the robot measured between the center of both wheels
     * in millimetres.
     */
    private final float TRACK_WIDTH = 135.0f;
    
    /**
     * The light level value where black and white light level is 
     * differentiated.
     */
    private final int LIGHT_BOUNDARY = 40;
	
	/**
	 * The 'actual' degree rotation needed to turn the robot 90 degrees.
	 * This number may be adjusted depending on frictional surfaces.
	 */ 
	private final int TURN_90_DEGREES = 90;
	
	/**
	 * Use this boolean to turn the robot left via the 'rotation' method.
	 */
	private final boolean TURN_LEFT = true;
	
	/**
	 * Use this boolean to turn the robot right via the 'rotation' method.
	 */
	private final boolean TURN_RIGHT = false;
	
	/**
	 * The distance, in degree rotations, from the center of a cell to the 
	 * point where the ultrasonic sensor is peeking out of the edge of the
	 * cell.
	 */
	private final int centerToEdgeDistance = 240;
	
	/**
	 * Safe edge count.
	 */
	private int safeEdgeCount = 0;
	
	/**
	 * WE BUILT THIS CITY! WE BUILT THIS CITY! WE BUILT THIS CITY ON ROCK & ROLL!
	 * Boolean variables that determine which directions are safe and which are
	 * not. True for safe, false for unsafe.
	 */
	private boolean forwardIsSafe = false;
	private boolean rightIsSafe = false;
	private boolean backwardIsSafe = false;
	private boolean leftIsSafe = false;
	
	/**
	 * Standard black/white threshold value.
	 */
	private static final int BLACK_WHITE_THRESHOLD = 40;
	
	/**
	 * Generates a random int between 0 and 1.
	 */
	private int randomNum = (int)(Math.random() * 2);
	
	/**
	 * The obstacle detector object.
	 */
	private ObstacleDetector obsDetObj;
	
	/**
	 * Random generator.
	 */
	private Random rand;
	
	/**
	 * List to store all possible locations to go to.
	 */
	private ArrayList<Integer> list;
	
	private int testInt = 0;
	
	/**
	 * Constructor: creates the MissionThree class.
	 */
	public MissionThree()
	{
		ultrasonicSensor = new UltrasonicSensor(ultrasonicSensorPort);
		System.out.println(ultrasonicSensorPort);
		lightSensor = new LightSensor(lightSensorPort);
		touchSensor = new TouchSensor(touchSensorPort);
		lightSensorDown = new LightSensor(lightSensorDownPort);

        pilot = new DifferentialPilot(WHEEL_DIAMETER, 
                                      TRACK_WIDTH,
                                      leftMotor,
                                      rightMotor);
		obsDetObj = new ObstacleDetector();
		obsDetObj.start();
		
		list = new ArrayList<Integer>();
		rand = new Random();
	}
	
	/**
	 * Main method.
	 */
	public static void main(String[] args)
	{
		final MissionThree robot;
		robot = new MissionThree();
		
		robot.run();
	}
	
	/**
	 * Run.
	 */
	public void run()
	{
		while(true)
		{
			Motor.A.setSpeed(180);
			Motor.C.setSpeed(180);
		
			pilot.setRotateSpeed(45);
		
			// Check forward edge
			forwardIsSafe = stopBeforeEdge();
			Motor.A.backward();
			Motor.C.backward();
			if(forwardIsSafe == true)
			{
				Delay.msDelay(1500);
			}
			else
			{
				Delay.msDelay(1000);
			}
			rotation(TURN_90_DEGREES, TURN_RIGHT);
		
			Motor.A.setSpeed(180);
			Motor.C.setSpeed(180); 
			
			// Check right edge
			rightIsSafe = stopBeforeEdge();
			Motor.A.backward();
			Motor.C.backward();
			if(rightIsSafe == true)
			{
				Delay.msDelay(1300);
			}
			else
			{
				Delay.msDelay(1000);
			}
			rotation(TURN_90_DEGREES, TURN_RIGHT);
			
			Delay.msDelay(500);
			rotation(TURN_90_DEGREES, TURN_RIGHT);
			
			Motor.A.setSpeed(180);
			Motor.C.setSpeed(180);
			
			// Check left edge
			leftIsSafe = stopBeforeEdge();
			Motor.A.backward();
			Motor.C.backward();
			if(leftIsSafe == true)
			{
				Delay.msDelay(1300);
			}
			else
			{
				Delay.msDelay(1000);
			}
			rotation(TURN_90_DEGREES+1, TURN_RIGHT);
			
			Motor.A.setSpeed(180);
			Motor.C.setSpeed(180);
			
			if((forwardIsSafe == false) && (rightIsSafe == false) && (leftIsSafe == false))
			{	
				System.out.println("Backing up");
				backwardIsSafe = true;
				rotation(TURN_90_DEGREES, TURN_RIGHT);
				Delay.msDelay(500);
				rotation(TURN_90_DEGREES, TURN_RIGHT);
				pilot.travel(280);
				continue;
			}
		
			System.out.println("Forward: " + forwardIsSafe);
			System.out.println("Right: " + rightIsSafe);
			System.out.println("Backward: " + backwardIsSafe);
			System.out.println("Left: " + leftIsSafe);
			System.out.println("Total Safe: " + safeEdgeCount);
			
			//forward: 1, right: 2, back: 3, left: 4
			
			//Clear the list from before
			list.clear();
			if(forwardIsSafe)
			{
				list.add(1);
			}
			
			if(rightIsSafe)
			{
				list.add(2);
			}
			
			if(backwardIsSafe && !forwardIsSafe && !leftIsSafe && !rightIsSafe)
			{
				list.add(3);
			}
			
		
			if(leftIsSafe)
			{
				list.add(4);
			}
		
			Integer num = new Integer(-1);
		
			if(list.size() == 0)
			{
			}
			else{
			int index = rand.nextInt( list.size() );
			if(index > -1){
				num = list.get(index);
			}
			else
				num = -1; //Hopefully this doesn't happen
		}
		
		if(num == 1) // Forward
		{
			//Motor.A.setSpeed(180);
			//Motor.C.setSpeed(180);
			if (touchSensor.isPressed())
			{
				pilot.stop();
			}
			else
			{			
				pilot.setRotateSpeed(45);
				pilot.travel(280);
			}
		}
		else
		if(num == 2) // Right
		{
			rotation(TURN_90_DEGREES, TURN_RIGHT);
			//Motor.A.setSpeed(180);
			//Motor.C.setSpeed(180);
			pilot.setRotateSpeed(45);
			pilot.travel(280);
		}
		else
		if(num == 3) // Backward
		{
			rotation(TURN_90_DEGREES, TURN_RIGHT);
			Delay.msDelay(500);
			rotation(TURN_90_DEGREES, TURN_RIGHT);
			//Motor.A.setSpeed(180);
			//Motor.C.setSpeed(180);
			pilot.setRotateSpeed(45);
			pilot.travel(280);
		}
		else
		if(num == 4) // Left
		{
			rotation(TURN_90_DEGREES, TURN_LEFT);
			//Motor.A.setSpeed(180);
			//Motor.C.setSpeed(180);
			pilot.setRotateSpeed(45);
			pilot.travel(280);
		}
		}
	}
	
	/**
	 * Stops the robot when the ultrasonic sensor detects a certain distance.
	 *
	 * @param stopDistance as long as the current distance is less than this
	 * stop distance, the robot will keep moving. Once the current distance is
	 * larger than the stop distance, the function returns.
	 *
	 * @return the current distance upon stopping.
	 */
	private boolean stopBeforeEdge()
	{	
		int currentDistance = 0;
		int lightLevelReading;
		int distanceToObject;
		boolean edgeIsSafe = false;
		
		Motor.A.rotate(centerToEdgeDistance, true);
		Motor.C.rotate(centerToEdgeDistance, true);
		
		do
		{
			lightLevelReading = lightSensorDown.readValue();
		}
		while((lightLevelReading > BLACK_WHITE_THRESHOLD) && (Motor.A.isMoving() && Motor.C.isMoving()));
		
		pilot.stop();

		lightLevelReading = lightSensorDown.readValue();
		distanceToObject = ultrasonicSensor.getDistance();
		
		if(distanceToObject < 20)
		{
			edgeIsSafe = true;
			Motor.A.setSpeed(1000);
			Motor.C.setSpeed(1000);
			pilot.setRotateSpeed(1000);
			pilot.travel(280);
			Delay.msDelay(10000);
			return(edgeIsSafe);
		}
		
		if(lightLevelReading < BLACK_WHITE_THRESHOLD)
		{
			System.out.println("Unsafe edge");
			edgeIsSafe = false;
			
			distanceToObject = ultrasonicSensor.getDistance();
			if(distanceToObject < 20)
			{
				Motor.A.setSpeed(1000);
				Motor.C.setSpeed(1000);
				pilot.setRotateSpeed(1000);
				pilot.travel(280);
				Delay.msDelay(10000);
				return(edgeIsSafe);
			}	
			return(edgeIsSafe);
		}
		else if (lightLevelReading > BLACK_WHITE_THRESHOLD)
		{
			System.out.println("Safe edge");
			edgeIsSafe = true;
			safeEdgeCount++;
			return(edgeIsSafe);
		}
		
		return(edgeIsSafe);
	}
	
	/**
	 * Turns the robot left or right depending on a random number.
	 */
	private void turnLeftOrRight()
	{
		randomNum = (int)(Math.random() * 2);
		
		if(randomNum == 0)
		{
			rotation(TURN_90_DEGREES, TURN_RIGHT);
		}
		else
		if(randomNum == 1)
		{
			rotation(TURN_90_DEGREES, TURN_LEFT);
		}
	}
	
	/**
	 * Rotates the robot a specified number of degrees left or right.
	 * 
	 * @param turnDegrees the degree of the turn.
	 * @param turnLeft true to turn left, false to turn right.
	 */
	public void rotation(int turnDegrees, boolean turnLeft)
	{
		if(turnLeft == true)
		{
			pilot.rotate(turnDegrees);
		}
		else
		{
			pilot.rotate(-turnDegrees);
		}
	}
}