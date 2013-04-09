import lejos.nxt.UltrasonicSensor;
import lejos.nxt.TouchSensor;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.SensorPort;
import lejos.nxt.Motor;

/* IMPORTANT! READ BEFORE EXECUTING CODE: 
    - Make sure that the left wheel motor is connected to Port C
    - Make sure that the right wheel motor is connected to Port A
    - Make sure that the ultrasonic sensor is connected to Port 1
    - Make sure that the light sensor is connected to Port 2
    - TODO: port for touch sensor(s) here.
   Otherwise, change the code in the class variables. Note that this is the only
   place you'd have to make any changes.
*/

/**
 * This program prints the current light level as detected by the robot's
 * light sensor and prints it on the NXT brick screen.
 */
public class MissionTwo
{
    /**
     * The wheel diameter of each of the robot's wheels written on the side of
     * the tire in millimetres.
     */
    private static final float WHEEL_DIAMETER = 56.0f;
    
    /**
     * The track width of the robot measured between the center of both wheels
     * in millimetres.
     */
    private static final float TRACK_WIDTH = 114.0f;
    
    /**
     * The light level value where black and white light level is 
     * differentiated.
     */
    private static final int LIGHT_BOUNDARY = 40;
    
    
    /**
     * The light sensor.
     */
    private static MissionTwoLightSensor lightSensor;
    
    /**
     * The port for the light sensor is set to Port 2.
     */
    private static final SensorPort lightSensorPort = SensorPort.S2;
    
    private final DifferentialPilot pilot;
    
    private final RegulatedMotor rightMotor = Motor.A;
    
    private final RegulatedMotor leftMotor = Motor.C;
    
    private final SensorPort ultrasonicPort = SensorPort.S1;
    
    private final UltrasonicSensor ultrasonicSensor;
    
    /**
     * Constructor for MissionTwo class.
     */
    public MissionTwo()
    {
        lightSensor = new MissionTwoLightSensor(lightSensorPort);
        ultrasonicSensor = new UltrasonicSensor(ultrasonicPort);
        pilot = new DifferentialPilot(WHEEL_DIAMETER, 
                                        TRACK_WIDTH,
                                        leftMotor,
                                        rightMotor);
        lightSensor.start();
    }
    
    /** 
     * The main method.
     */
    public static void main(String[] args)
    {
        final MissionTwo robot;
        robot = new MissionTwo();
        
        // robot.exploreRoom(robot);
		
		int rotationAmount = 0;
		int shortestDistance = 0;
		
		for(rotationAmount = 0; rotationAmount <= 380; rotationAmount = rotationAmount + 10)
		{
			pilot.rotate(10);
			System.out.println("Rotated: " + rotationAmount);
			
			shortestDistance = ultrasonicSensor.getDistance();
			System.out.println("Shortest Distance: " + shortestDistance);
		}
    }
    
    /** 
     * Moves the robot around the room while scanning for a door.
     */
    private void exploreRoom(MissionTwo robot)
    {
        int currentReading;
        boolean doorIsOpened = false;
        int numOfTurns = 0;
        
        do 
        {
            currentReading = lightSensor.getReading();
            
            //Change motor speed here, as well as distance from wall
            robot.moveForwardUntilWall(360, 20);
            pilot.rotate(90);
            numOfTurns++;
            
            if (isADoor(currentReading))
            {
                System.out.println("Opening door");
                pilot.rotate(-90);
                pilot.rotate(90);
                //doorIsOpened = openDoor();
            }
        }
        while (!doorIsOpened && (numOfTurns <= 4));
        lightSensor.interrupt();
        
        //Code to exit the room goes here.
    }
	
	private void goToWall()
	{
		
	}
    
    /**
     * Opens a door.
     * @return true if the door was successfully opened, false otherwise.
     */
    private boolean openDoor()
    {
        
        //set motor speed.
        //move forward.
        //scan touch sensor; see if it is pressed.
        //if the touch sensor is un-pressed after three pushes to the door,
            //then the door is opened.
        //the door is locked.
        
        throw new UnsupportedOperationException("Not implemented yet!");
    }
    
    /**
     * Verifies if the light level of the obstacle is a door
     * @param obstacleLightLevel the light level of the obstacle.
     * @return true if the obstacle is a door, false otherwise.
     */
    private boolean isADoor(final int obstacleLightLevel)
    {
        if (obstacleLightLevel > LIGHT_BOUNDARY)
        {
            System.out.println("Obstacle is a door");
            return true;
        }
        
        return false;
    }
    
	/**
     * Function for the Robot to move forward until an obstacle is detected by
     * the ultrasonic sensor.
     * @param motorSpeed the turning speed of each of the wheels.
     * @param detectionDistance the ultrasonic sensor will detect an obstacle 
     within this distance (in centimeters).
     */
	public void moveForwardUntilWall(int motorSpeed, int detectionDistance)
	{
        int distanceFromObstacle;
        
		leftMotor.setSpeed(motorSpeed);
		rightMotor.setSpeed(motorSpeed);
		
		moveForward();
		distanceFromObstacle = waitForDistance(detectionDistance);
		
		/*System.out.println("Distance from detected obstacle: " 
                        + distanceFromObstacle);*/
	}
	
	/**
	 * Moves the robot forward.
	 */
    private void moveForward()
    {
        leftMotor.forward();
        rightMotor.forward();
    }
    
    /**
	 * Calculate how far is the robot from an obstacle using the ultrasonic 
	 sensor. 
	 * @param max the ultrasonic sensor will detect an obstacle within this 
	 distance (in centimeters).
	 *
	 * @return the distance at which the robot's ultrasonic sensor has detected 
	 an obstacle (in centimeters).
	 *
	 */
	private int waitForDistance(final int max)
	{
		int distance;
		
		do
		{
			try
			{
				/* pause 100 ms between reads...
				this is a LeJOS issue
				later versions of LEJOS won't require this */
				Thread.sleep(100);
			}
			catch(InterruptedException ex)
			{
            }
			
			distance = ultrasonicSensor.getDistance();
		}
		while(distance > max);
		
		return(distance);
	}
	
}