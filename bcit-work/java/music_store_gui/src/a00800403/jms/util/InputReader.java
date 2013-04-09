package a00800403.jms.util;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import a00800403.jms.data.MusicalInstrument;

/**
 * InputReader.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class InputReader
{
    private Scanner scanner;
	private static final String TEXT_FILENAME = "inventory.txt";
	private int numberOfRows;

    /**
     * Create a new InputReader to read user input.
     */
    public InputReader()
    {
        scanner = new Scanner(System.in);
    }

    /**
     * Gets the user's input 
     * @return the user's input as a String
     */
    public String getInput()
    {
        return scanner.nextLine();
    }
    
	public Object[] readTextData() throws FileNotFoundException {

		System.out.println("DEBUG *** Reading Student data from the file...");
		MusicalInstrument[] inputData = new MusicalInstrument[numberOfRows];

		Scanner scanner = null;
		File file = new File(TEXT_FILENAME);

		if (!file.exists()) {
			System.err.println("File " + TEXT_FILENAME + " does not exist.");
			System.exit(0);
		}

		scanner = new Scanner(new File(TEXT_FILENAME));

		for (int i = 0; i < numberOfRows; i++) {
			String line = scanner.nextLine();
			String[] itemData = line.split("\\|");

			inputData[i] = new MusicalInstrument(itemData[0], itemData[1], Double.parseDouble(itemData[2]),
					Double.parseDouble(itemData[3]));
		}

		return inputData;
	}
    
	public static ArrayList<MusicalInstrument> createDataListFromTextFile()
			throws FileNotFoundException {

		System.out.println("DEBUG *** Reading Student data from the file...");
		ArrayList<MusicalInstrument> inputData = new ArrayList<MusicalInstrument>();

		Scanner scanner = null;
		File file = new File(TEXT_FILENAME);

		if (!file.exists()) {
			System.err.println("File " + TEXT_FILENAME + " does not exist.");
			System.exit(0);
		}

		scanner = new Scanner(new File(TEXT_FILENAME));

		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			String[] itemData = line.split("\\|");

			inputData.add(new MusicalInstrument(itemData[0], itemData[1], Double.parseDouble(itemData[2]),
					Double.parseDouble(itemData[3])));
		}

		return inputData;
	}
	
	public static void printArray(ArrayList<MusicalInstrument> instruments) {

		if (instruments.size() > 0) {
			for (MusicalInstrument instrument : instruments) {

				System.out.println(formatInstrument(instrument));
			}
		}

	}
	
	private static String formatInstrument(MusicalInstrument instrument) {

		return String.format("Description: %s, SKU: %s, Purchase Price: $%s, Selling Price: $%s",
				instrument.getDescription(), instrument.getStockCode(),
				instrument.getPurchasePrice(),
				instrument.getSellingPrice());
	}

}
