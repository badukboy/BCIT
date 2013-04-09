import lejos.nxt.Motor;
import lejos.robotics.RegulatedMotor;
import lejos.robotics.navigation.DifferentialPilot;
import lejos.nxt.SensorPort;
import lejos.nxt.UltrasonicSensor;


public class GoCircle
{
    private final SensorPort ultrasonicPort;
    private final UltrasonicSensor ultrasonicSensor;
    
    public GoCircle()
    {
        ultrasonicPort = SensorPort.S1;
        ultrasonicSensor = new UltrasonicSensor(ultrasonicPort);
    }
    
    public static void main (String[] args)
    {
        final float wheelDiameter;
        final float trackWidth;
        final RegulatedMotor leftMotor;
        final RegulatedMotor rightMotor;
        final DifferentialPilot pilot;
        
        final GoCircle robot;
        robot = new GoCircle();
     
        //56 mm (written on the side of the tire)
        wheelDiameter = 56.0f;
        
        //114 mm (measured between the centre of both wheels)
        trackWidth = 114.0f;
        leftMotor = Motor.B;
        rightMotor = Motor.A;
        pilot = new DifferentialPilot(wheelDiameter, trackWidth,
                                        leftMotor, rightMotor);
                                        
        robot.run();
        pilot.steer(-90, -180);
        robot.run();
        pilot.steer(90,180);
        robot.run();
    }
    
    public void run()
    {
        //Motor.A.setSpeed(720);
        //Motor.B.setSpeed(720);
        
        moveForward();
        
        waitForDistance(30);
    }
    
    private int waitForDistance(final int max)
    {
        int distance;
        
        do 
        {
            try
            {
                Thread.sleep(100);
            }
            catch(InterruptedException ex)
            {
            }
            distance = ultrasonicSensor.getDistance();
        }
        while(distance > max);
        
        return (distance);
    }
    
    private void moveForward()
    {
        Motor.B.forward();
        Motor.A.forward();
    }
}