package a00800403.jms.data;

import a00800403.jms.util.InputReader;

/**
 * Customer.java
 * 
 * Data class that represents a customer for a store.
 * 
 * @author Kevin Csapko, A00800403
 */
public class Customer
{
	/**
	 * Customer first name.
	 */
	private String firstName;
	
	/**
	 * Customer last name.
	 */
	private String lastName;
	
	/**
	 * Customer credit card number.
	 */
	private String creditCardNumber;
	
	/**
	 * Customer address.
	 */
	private String address;
	
	/**
	 * Customer phone number.
	 */
	private String phoneNumber;
	
	/**
	 * Default constructor: collects data via console input.
	 */
	public Customer()
	{
		InputReader inputReader = new InputReader();
		
		this.firstName = 		inputReader.getInput();
		this.lastName = 		inputReader.getInput();
		this.creditCardNumber =	inputReader.getInput();
		this.address = 			inputReader.getInput();
		this.phoneNumber =		inputReader.getInput();
	}
	
	/**
	 * Constructor: sets up an instance of the Customer object.
	 * 
	 * @param firstName 		Customer first name.
	 * @param lastName 			Customer last name.
	 * @param creditCardNumber	Customer credit card number.
	 * @param address 			Customer address.
	 * @param phoneNumber 		Customer phone number.
	 */
	public Customer(String firstName, String lastName, String creditCardNumber,
			String address, String phoneNumber)
	{
		this.firstName = 		firstName;
		this.lastName = 		lastName;
		this.creditCardNumber =	creditCardNumber;
		this.address = 			address;
		this.phoneNumber = 		phoneNumber;
	}
	
	/**
	 * Accessor: customer's first name.
	 * 
	 * @return firstName 	Formatted so that the first letter is uppercase
	 * 						and the remaining letters are lowercase.
	 */
	public String getFirstName()
	{
		int firstNameLength = firstName.length();
		
		firstName = firstName.substring(0, 1).toUpperCase().
				concat(firstName.substring(1, firstNameLength).toLowerCase());
		
		return firstName;
	}
	
	/**
	 * Mutator: customer's first name.
	 * 
	 * @param firstName 	Validated to ensure that the string is not null and
	 * 						is at least one character in length.
	 */
	public void setFirstName(String firstName)
	{
		if(firstName != null && !firstName.isEmpty())
		{
			this.firstName = firstName;
		}
	}

	/**
	 * Accessor: customer's last name.
	 * 
	 * @return lastName	Formatted so that the first letter is uppercase and the
	 * 					remaining letters are lowercase.
	 */
	public String getLastName()
	{
		int lastNameLength = lastName.length();
		
		lastName = lastName.substring(0, 1).toUpperCase().
				concat(lastName.substring(1, lastNameLength).toLowerCase());
		
		return lastName;
	}
	
	/**
	 * Mutator: customer's last name.
	 * 
	 * @param lastName	Validated to ensure that the string is not null and is
	 * 					at least one character in length.
	 */
	public void setLastName(String lastName)
	{
		if(lastName != null && !lastName.isEmpty())
		{
			this.lastName = lastName;
		}
	}
	
	/**
	 * Accessor: customer's credit card number.
	 * 
	 * @return creditCardNumber
	 */
	public String getCreditCardNumber()
	{
		return creditCardNumber;
	}
	
	/**
	 * Mutator: customer's credit card number.
	 * 
	 * @param creditCardNumber
	 */
	public void setCreditCardNumber(String creditCardNumber)
	{
		this.creditCardNumber = creditCardNumber;
	}
	
	/**
	 * Accessor: customer's address.
	 * 
	 * @return address
	 */
	public String getAddress()
	{
		return address;
	}
	
	/**
	 * Mutator: customer's address.
	 * 
	 * @param address	Validated to ensure that the string is not null and is
	 * 					at least one character in length.
	 */
	public void setAddress(String address)
	{
		if(address != null && !address.isEmpty())
		{
			this.address = address;
		}
	}
	
	/**
	 * Accessor: customer's phone number.
	 * 
	 * @return phoneNumber
	 */
	public String getPhoneNumber()
	{
		return phoneNumber;
	}
	
	/**
	 * Mutator: customer's phone number.
	 * 
	 * @param phoneNumber
	 */
	public void setPhoneNumber(String phoneNumber)
	{
		this.phoneNumber = phoneNumber;
	}
	
	/**
	 * Accessor: customer's full name.
	 * 
	 * @return fullName	The customer's formatted first and last name via their
	 * 					accessor methods, concatenated to form a full name.
	 */
	public String getFullName()
	{
		String fullName = getFirstName() + " " + getLastName();
		
		return fullName;
	}

	/**
	 * Standard toString() method.
	 */
	@Override
	public String toString()
	{
		return 	"Customer full name: " + getFullName() + "\n" +
				"First name: " + getFirstName() + "\n" +
				"Last name: " + getLastName() + "\n" +
				"Credit card number: " + getCreditCardNumber() + "\n" +
				"Address: " + getAddress() + "\n" +
				"Phone number: " + getPhoneNumber();
	}
	
	
}
