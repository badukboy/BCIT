import lejos.nxt.UltrasonicSensor;
import lejos.nxt.TouchSensor;
import lejos.robotics.objectdetection.RangeFeatureDetector;
import lejos.robotics.objectdetection.TouchFeatureDetector;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.SensorPort;
import lejos.nxt.Motor;

import lejos.nxt.Button;


/* IMPORTANT! READ BEFORE EXECUTING CODE: 
    - Make sure that the left wheel motor is connected to Port C
    - Make sure that the right wheel motor is connected to Port A
 
     */
    private static final int LIGHT_BOUNDARY = 40;
    
    
    /**
     * The light sensor.
     */
    private MissionTwoLightSensor lightSensor;
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
    
 
        final MissionTwo robot;
        robot = new MissionTwo();
        
        robot.exploreRoom();
        robot.exploreRoom(robot);
    }
    
    /** 
     * Moves the robot around the room while scanning for a door.
     */
    public void exploreRoom()
    private void exploreRoom(MissionTwo robot)
    {
        int currentReading;
        boolean doorIsOpened = false;
        int numOfTurns = 0;
        
        do 
        {
            currentReading = lightSensor.getReading();
            
            //Change here
            robot.moveForwardUntilWall(360, 20);
            pilot.rotate(90);
            numOfTurns++;
            
            if (isADoor(currentReading))
            {
                doorIsOpened = openDoor();
                System.out.println("Opening door");
                //pilot.rotate(-90);
                //doorIsOpened = openDoor();
            }
        }
        while (!doorIsOpened);
        while (!doorIsOpened && (numOfTurns <= 4));
        
        lightSensor.interrupt();
        //exit the room.
        
        //Code to exit the room goes here.
    }
    
    /**
 
        
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
                System.out.println("Caught: " + ex.getMessage());
			}
			
			distance = ultrasonicSensor.getDistance();
		}
		while(distance > max);
		
		return(distance);
	}
	
}