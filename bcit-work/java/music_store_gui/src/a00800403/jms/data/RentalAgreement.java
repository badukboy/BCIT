package a00800403.jms.data;

import java.text.NumberFormat;
import java.util.GregorianCalendar;
import a00800403.jms.util.DateUtil;

/**
 * RentalAgreement.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class RentalAgreement
{
	/**
	 * The customer renting the instrument(s).
	 */
	private Customer rentalCustomer;
	
	/**
	 * Rental agreement date.
	 */
	private GregorianCalendar rentalDate;
	
	/**
	 * The type of instrument rented.
	 */
	private MusicalInstrument instrumentRented;
	
	/**
	 * Daily rental fee.
	 */
	private double rentalFeePerDay;
	
	/**
	 * Number of days for rental.
	 */
	private int numberOfDaysRented;
	
	/**
	 * Total rental fee.
	 */
	private double totalRentalFee;
	
	/**
	 * Constructor: sets up an instance of the RentalAgreement object.
	 * 
	 * @param rentalCustomer	The customer rented the instrument(s).
	 * @param rentalDate		The date of the rental.
	 * @param instrumentRented	The type of instrument rented.
	 */
	public RentalAgreement(Customer rentalCustomer, GregorianCalendar rentalDate,
			MusicalInstrument instrumentRented)
	{
		this.rentalCustomer = rentalCustomer;
		this.rentalDate = rentalDate;
		this.instrumentRented = instrumentRented;
	}

	/**
	 * Accessor: the daily rental fee.
	 * 
	 * @return rentalFeePerDay
	 */
	public double getRentalFeePerDay()
	{
		return rentalFeePerDay;
	}

	/**
	 * Mutator: the daily rental fee.
	 * 
	 * @param rentalFeePerDay	Validated to ensure the daily rental fee must
	 * 							be greater than $0.00.
	 */
	public void setRentalFeePerDay(double rentalFeePerDay)
	{
		if(rentalFeePerDay > 0.00)
		{
			this.rentalFeePerDay = rentalFeePerDay;
		}
		else
		{
			System.err.println("Error: the daily rental fee must be greater"
					+ " than $0.00.");
		}
	}

	/**
	 * Accessor: the number of rental days.
	 * 
	 * @return numberOfDaysRented
	 */
	public int getNumberOfDaysRented()
	{
		return numberOfDaysRented;
	}

	/**
	 * Mutator: the number of rental days.
	 * 
	 * @param numberOfDaysRented	Validated to ensure the number of days
	 * 								rented is less than 32 and greater than 0.
	 */
	public void setNumberOfDaysRented(int numberOfDaysRented)
	{
		if(numberOfDaysRented > 0 && numberOfDaysRented < 32)
		{
			this.numberOfDaysRented = numberOfDaysRented;
		}
		else
		{
			System.err.println("Error: the rental period must not be less than"
					+ " 1 day or greater than 31 days.");
		}
	}

	/**
	 * Accessor: the total rental fee based on the daily rental fee and number
	 * of days rented.
	 * 
	 * @return totalRentalFee
	 */
	public double getTotalRentalFee()
	{
		totalRentalFee = rentalFeePerDay * numberOfDaysRented;
		
		return totalRentalFee;
	}

	/**
	 * Mutator: the total rental fee.
	 * 
	 * @param totalRentalFee
	 */
	public void setTotalRentalFee(double totalRentalFee)
	{
		this.totalRentalFee = totalRentalFee;
	}

	/**
	 * Accessor: the customer renting the instrument(s).
	 * 
	 * @return rentalCustomer
	 */
	public Customer getRentalCustomer()
	{
		return rentalCustomer;
	}

	/**
	 * Accessor: the date of the rental.
	 * 
	 * @return rentalDate
	 */
	public GregorianCalendar getRentalDate()
	{
		return rentalDate;
	}

	/**
	 * Accessor: the type of instrument rented.
	 * 
	 * @return instrumentRented
	 */
	public MusicalInstrument getInstrumentRented()
	{
		return instrumentRented;
	}
	
	/**
	 * Prints information about the rental agreement to the console.
	 */
	public void displayRentalInformation()
	{
		NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance();
		
		System.out.println("Customer: " + rentalCustomer.getFullName());
		System.out.println("Rental date: " + DateUtil.format(rentalDate));
		System.out.println("Instrument rented: " + instrumentRented.getDescription());
		System.out.println("Fee per day: " + 
				currencyFormatter.format(getRentalFeePerDay()));
		System.out.println("Number of days rented: " + numberOfDaysRented);
		System.out.println("Total rental fee: " + 
				currencyFormatter.format(getTotalRentalFee()));
	}
}
