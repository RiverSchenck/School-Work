package cs;
import robocode.*;
//import java.awt.Color;

// API help : http://robocode.sourceforge.net/docs/robocode/robocode/Robot.html

/**
 * BestRobot - a robot by (your name here)
 */
public class BestRobot extends AdvancedRobot
{

	private byte scanDirection = 1;


	public void run() {
	

	
		
		while(true) {
	
			ahead(100);
			turnGunRight(360);
			back(100);
			turnGunRight(360);
			
			
			
			
		}
	}

	/**
	 * onScannedRobot: What to do when you see another robot
	 */
	public void onScannedRobot(ScannedRobotEvent e) {
	
	if (e.getDistance() < 400)
		{
			fire(3);
		}
		else
		{
			fire(1);
		}


	}

	/**
	 * onHitByBullet: What to do when you're hit by a bullet
	 */
	public void onHitByBullet(HitByBulletEvent e) {
		// Replace the next line with any behavior you would like
		back(200);
	}
	
	/**
	 * onHitWall: What to do when you hit a wall
	 */
	public void onHitWall(HitWallEvent e) {
		// Replace the next line with any behavior you would like
		back(100);
		turnRight(250);
	}	
}
