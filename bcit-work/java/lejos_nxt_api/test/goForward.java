import lejos.nxt.Motor;

public class goForward
{
	public static void main(String[] args)
	{
		Motor.A.setSpeed(360);
		Motor.B.setSpeed(360);
		
		// rotate wheels A and B 360 degrees 5 times
		Motor.A.rotate(360 * 5, true);
		Motor.B.rotate(360 * 5, true);
		
		// keep the program running until both motors have stopped
		while(Motor.A.isMoving() && Motor.B.isMoving())
		{
		}
	}
}