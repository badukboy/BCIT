import lejos.nxt.Motor;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.SensorPort;
import lejos.nxt.UltrasonicSensor;
import lejos.nxt.LightSensor;

public class MissionKevin 
{
	/* Light sensor */
	private final SensorPort lightPort;
	private final LightSensor lightSensor;
	
	/* Ultrasonic sensor */
	private final SensorPort ultrasonicPort;
    private final UltrasonicSensor ultrasonicSensor;
	
	public static void main(String[] args)
	{
		final MissionKevin robot;
		
		final float wheelDiameter;
		final float trackWidth;
		final RegulatedMotor leftMotor;
		final RegulatedMotor rightMotor;
		final DifferentialPilot pilot;
		
		/* 56mm (written on the side of the tire) */
		wheelDiameter = 56.0f;
		
		/* 114mm (measured between the centre of both wheels) */
		trackWidth = 114.0f;
		
		leftMotor = Motor.A;
		rightMotor = Motor.B;
		
		pilot = new DifferentialPilot(wheelDiameter, 
									  trackWidth, 
									  leftMotor, 
									  rightMotor);

		robot = new MissionKevin();
		
		/* MISSION 1 START */
		robot.run();
		pilot.steer(90, 90);
		robot.run();
		pilot.steer(95, 95);
		robot.run();
		pilot.steer(-90, -90);
		robot.run();
		pilot.steer(-95, -95);
		robot.run();
		/* MISSION 1 END */
	}
	
	/* Constructor */
	public MissionKevin()
	{
		/* Light sensor hooked up to port S3 */
		lightPort = SensorPort.S3;
		lightSensor = new LightSensor(lightPort);
		lightSensor.setFloodlight(true);
		
		/* Ultrasonic sensor hooked up to port S1 */
		ultrasonicPort = SensorPort.S1;
		ultrasonicSensor = new UltrasonicSensor(ultrasonicPort);
	}
	
	/* Run the robot */
	public void run()
	{
		Motor.A.setSpeed(360);
		Motor.B.setSpeed(360);
		
		/* Move the robot forward... */
		moveForward();
		
		/* ...Until the ultrasonic sees somthing within 'x' cm */
		waitForDistance(20);
		
		/* ...Until the light sensor sees something within 'x' cm */
		waitForLight(40);
	}
	
	/* Stops the robot before it touches a wall */
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
	
	/* Stops the robot before it hits a dark area */
	private int waitForLight(final int max)
	{
		int light;
		
		do
		{
			light = lightSensor.readValue();
		}
		while(light > max);
		
		return(light);
	}
	
	/* Move the robot forward */
	private void moveForward()
	{
		Motor.A.forward();
		Motor.B.forward();
	}
}
