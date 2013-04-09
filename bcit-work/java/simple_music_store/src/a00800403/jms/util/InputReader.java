package a00800403.jms.util;

import java.util.Scanner;

/**
 * InputReader.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class InputReader
{
    private Scanner scanner;

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
}
