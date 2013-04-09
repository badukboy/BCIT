import lajogs.nxt.Motor;
import lajos.nxt.SensorPort;
import lejos.nxt.UltrasonicSensor;

public class StopBeforeImpact
{
	private final SensorPort ultrasonicPort;
	private final UltrasonicSensor unltrasonicSensor;
	
	public static void main(String[] args)
	{
		final StopBeforeImpact robot;
		
		robot = new StopBeforeImpact();
		robot.run();
	}
	
	public StopBeforeImpact()
	{
		ultrasonicPort = SensorPort.S1;
		unltrasonicSensor = new UltrasonicSensor(ultrasonicPort);
	}
	
	public void run()
	{
		Motor.A.setSpeed(360);
		Motor.B.setSpeed(360);
		
		// go forward...
		moveForward();
		
		// ... until the ultrasonic sees something within 30cm
		waitForDistance(30);
	}
	
	private int waitForDistance(final int max)
	{
		int distance;
		
		do
		{
			try
			{
				// pause 100 ms between reads...
				// this is a LeJOS issue
				// later versions of LeJOS won't require this
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
	
	private void moveForward()
	{
		Motor.A.forward();
		Motor.B.forward();
	}
}