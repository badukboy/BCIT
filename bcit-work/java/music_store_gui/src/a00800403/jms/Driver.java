package a00800403.jms;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import a00800403.jms.data.MusicalInstrument;
import a00800403.jms.ui.JMSFrame;
import a00800403.jms.util.InputReader;

/**
 * Driver.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class Driver
{	
	public static ArrayList<MusicalInstrument> instruments;
	public static String instrumentString;
	
	public static void main(String[] args) throws FileNotFoundException
	{	
		File file = new File("inventory.txt");
		instruments = InputReader.createDataListFromTextFile();
		InputReader.printArray(instruments);
		
		
		JMSFrame frame = new JMSFrame();
		frame.setVisible(true);	
	}
}
