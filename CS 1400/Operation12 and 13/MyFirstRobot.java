package cs;
import robocode.*;
import java.awt.Color;

// API help : http://robocode.sourceforge.net/docs/robocode/robocode/Robot.html

/**
 * MyFirstRobot - a robot by (your name here)
 */
public class MyFirstRobot extends Robot
{
	/**
	 * run: MyFirstRobot's default behavior
	 */
	public void run() {
		
		// Set colors
		setBodyColor(Color.black);
		setGunColor(Color.black);
		setRadarColor(Color.yellow);
		setBulletColor(Color.black);
		setScanColor(Color.black);

		// Robot main loop
		while(true) {
			// Replace the next 4 lines with any behavior you would like
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
		// Replace the next line with any behavior you would like
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
		turnRight(45);
		back(100);
	}
	
	/**
	 * onHitWall: What to do when you hit a wall
	 */
	public void onHitWall(HitWallEvent e) {
		
		turnRight(90);
		ahead(75);

	}	
	
	public void onHitRobot (HitRobotEvent e) {
		back(50);
		ahead(100);
		
	
	}
	
	public void onWin	(WinEvent e){
		
		turnRight(360);
		turnGunLeft(360);
		ahead(10);
		turnLeft(360);
		turnGunLeft(360);
		ahead(10);

	}
	
	public void BulletHit (BulletHitBulletEvent e){
		
	fire(3);
	
	}
	
	public void onBulletHitBullet (BulletHitBulletEvent e){
		
	ahead(50);
	
	}

	public void onRobotDeath (RobotDeathEvent e){
		
		turnRight(360);
		turnLeft(360);
	}
}
