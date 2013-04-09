import lejos.nxt.Motor;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.UltrasonicSensor;
import lejos.nxt.SensorPort;
import lejos.nxt.Button;
import lejos.nxt.Sound;
import lejos.nxt.TouchSensor;
import lejos.util.Delay;

public class StartMissionTwo
{
	private final SensorPort ultrasonicPort;
	private static UltrasonicSensor ultrasonicSensor;
	private static final TouchSensor touch = new TouchSensor(SensorPort.S3);
 
	public StartMissionTwo()
	{
		ultrasonicPort = SensorPort.S1;
		ultrasonicSensor = new UltrasonicSensor(ultrasonicPort);
	}
 
	public static void main(String[] args)
	{
		// Standard declarations below
		final float wheelDiameter;
		final float trackWidth;
		final RegulatedMotor leftMotor;
		final RegulatedMotor rightMotor;
		final DifferentialPilot pilot;
		
		wheelDiameter = 56.0f;
		trackWidth = 114.0f;
		leftMotor = Motor.C;
		rightMotor = Motor.A;
		
		pilot = new DifferentialPilot(wheelDiameter,
									  trackWidth,
									  leftMotor,
								      rightMotor);
  
  
		final StartMissionTwo robot;
		robot = new StartMissionTwo();
  
		// *** PART 1: GETTING THE ROBOT PARALLEL TO THE WALL *** 
  
		// The counter used for the for loop
		int rotationAmount = 0;
		
		// The distance the object is from the robot in an interation of the for loop
		int distanceFromRobot = 0;
		
		// The shortest distance recorded from the robot as the for loop is processed
		int shortestDistance = 255;
		
		// The total degrees rotated by the robot as the for loop is processed
		int degreeRotation = 0;
		
		// The degrees rotated by the robot at the point a new shortest distance is found
		int referenceDegreeRotation = 0;
  
		/**
		 * For loop starts at 0 degrees turned. Continues looping as long as
		 * the degrees turned is less than or equal to 380 degrees. Each
		 * iteration of the loop increases the degrees turned by 10.
		 */
		for(rotationAmount = 0; rotationAmount <= 380; rotationAmount = rotationAmount + 10)
		{
			// Rotate the robot by 10 degrees
			pilot.rotate(10);
			
			// The robot has now turned +10 degrees
			degreeRotation = degreeRotation + 10;
   
			// Record the distance between the object and the robot at this point
			distanceFromRobot = ultrasonicSensor.getDistance();
   
			// If the distance just recorded is less than the lowest recorded distance...
			if(distanceFromRobot < shortestDistance)
			{
				// ...this newly recorded distance is now the lowest recorded distance
				shortestDistance = distanceFromRobot;
				// Record what degree this shortest distance was found
				referenceDegreeRotation = degreeRotation;
			}
		}
  
		// Rotate the robot perpendicularly with the wall
		pilot.rotate(referenceDegreeRotation + 10);
	
		// Drive towards the wall for 500ms (to ensure robot is perfectly perpendicular with the wall)
		Motor.A.setSpeed(360);
		Motor.C.setSpeed(360);
	
		Motor.A.forward();
		Motor.C.forward();
	
		while(!touch.isPressed());
		Delay.msDelay(500);
	
		// Move to robot backwards for 650ms
		Motor.A.backward();
		Motor.C.backward();
		Delay.msDelay(650);

		// Rotate the robot so that it is parallel to the wall
		pilot.rotate(98);
		
		// *** PART 2: DRIVE AROUND THE ROOM, PARALLEL TO THE WALL ***
		
		// Simple while loop makes the robot drive around the room
		int numOfTurns = 0;
		while(numOfTurns <= 4)
		{
			robot.run();
			pilot.rotate(98);
			numOfTurns++;
		}
		
		// *** PART 3: FIND WHITE WALLS AS PART 2 EXECUTES ***
		// TO DO: Ron
		
		// *** PART 4: CHECK TO SEE IF DOOR CAN OPEN
		// TO DO: Daniel & Taylor
	}
	
	public void run()
	{
		Motor.A.setSpeed(360);
		Motor.C.setSpeed(360);
		
		moveForward();
		
		waitForDistance(20);
	}
	
	private int waitForDistance(final int max)
	{
		int distance;
		
		do
		{
			try
			{
				/* Pause 100 ms between reads. This is a LeJOS issue.
				 * Later versions of LeJOS won't require this. */
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
	
	/* Move the robot forward */
	private void moveForward()
	{
		Motor.A.forward();
		Motor.C.forward();
	}
}