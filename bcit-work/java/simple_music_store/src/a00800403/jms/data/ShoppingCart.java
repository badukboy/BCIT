package a00800403.jms.data;

import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * ShoppingCart.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class ShoppingCart
{
	/**
	 * Contains all purchased instruments.
	 */
	private ArrayList<MusicalInstrument> purchasedInstruments;
	
	/**
	 * Contains all rental agreements.
	 */
	private ArrayList<RentalAgreement> rentalAgreements;
	
	/**
	 * Default constructor: sets up an instance of the ShoppingCart object.
	 */
	public ShoppingCart()
	{
		this.purchasedInstruments = new ArrayList<MusicalInstrument>();
		this.rentalAgreements = new ArrayList<RentalAgreement>();
	}

	/**
	 * Accessor: purchased instruments.
	 * 
	 * @return purchasedInstruments
	 */
	public ArrayList<MusicalInstrument> getPurchasedInstruments()
	{
		return purchasedInstruments;
	}

	/**
	 * Mutator: purchased instruments.
	 * 
	 * @param purchasedInstruments
	 */
	public void setPurchasedInstruments(
			ArrayList<MusicalInstrument> purchasedInstruments)
	{
		this.purchasedInstruments = purchasedInstruments;
	}

	/**
	 * Accessor: rental agreements.
	 * 
	 * @return rentalAgreements
	 */
	public ArrayList<RentalAgreement> getRentalAgreements()
	{
		return rentalAgreements;
	}

	/**
	 * Mutator: rental agreements.
	 * 
	 * @param rentalAgreements
	 */
	public void setRentalAgreements(
			ArrayList<RentalAgreement> rentalAgreements)
	{
		this.rentalAgreements = rentalAgreements;
	}
	
	/**
	 * Adds instruments to the list of purchased instruments. Updates inventory
	 * accordingly.
	 * 
	 * @param instrument	The type of instrument purchased.
	 * @param quantity		The quantity of that instrument purchased.
	 */
	public void addToPurchaseCart(MusicalInstrument instrument, int quantity)
	{	
		if(quantity <= instrument.getQuantityInStock())
		{
			for(int i = 0; i < quantity; i++)
			{
				purchasedInstruments.add(instrument);
			}
			
			instrument.setQuantitySold(quantity);
		}
		else
		{
			System.err.println("Error: you cannot purchase more items than"
					+ " those currently in stock.");
		}
	}
	
	/**
	 * Adds a rental agreement to the list of rental agreements.
	 * 
	 * @param agreement	A rental agreement.
	 */
	public void addToRentalCart(RentalAgreement agreement)
	{
		rentalAgreements.add(agreement);
	}
	
	/**
	 * Displays information about the purchased items and rental agreements.
	 * Includes a grand total for both lists.
	 */
	public void viewShoppingCarts()
	{
		NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance();
		Iterator<MusicalInstrument> musicalInstrumentsIterator = 
				purchasedInstruments.iterator();
		Iterator<RentalAgreement> rentalAgreementsIterator =
				rentalAgreements.iterator();
		double totalPurchaseCost = 	0.0;
		double totalRentalCost = 	0.0;
		
		System.out.println("You are purchasing the following items:");
		
		// Display purchase shopping cart...
		while(musicalInstrumentsIterator.hasNext())
		{
			MusicalInstrument instrument = musicalInstrumentsIterator.next();
			
			totalPurchaseCost += instrument.getSellingPrice();
			
			System.out.println(instrument.getDescription() + "\t" + 
					currencyFormatter.format(instrument.getSellingPrice()));
		}
		
		System.out.println("TOTAL:\t" + 
				currencyFormatter.format(totalPurchaseCost));
		
		System.out.println("\nYou are renting the following items:");

		// Display rental shopping cart...
		while(rentalAgreementsIterator.hasNext())
		{
			RentalAgreement agreement = rentalAgreementsIterator.next();
			
			totalRentalCost += agreement.getTotalRentalFee();
			
			System.out.println(agreement.getInstrumentRented().
					getDescription());
		}
		
		System.out.println("Rental fees due: " + 
				currencyFormatter.format(totalRentalCost));
	}
}
