package a00800403.jms.data;

import java.text.NumberFormat;

/**
 * MusicaInstrument.java
 * 
 * Data class that represents a musical instrument.
 * 
 * @author Kevin Csapko, A00800403
 */
public class MusicalInstrument
{
	/**
	 * Musical instrument description.
	 */
	private String description;
	
	/**
	 * Musical instrument stock code (SKU).
	 */
	private String stockCode;
	
	/**
	 * Musical instrument quantity in stock.
	 */
	private int quantityInStock;
	
	/**
	 * Musical instrument quantity sold.
	 */
	private int quantitySold;
	
	/**
	 * Musical instrument purchase price.
	 */
	private double purchasePrice;
	
	/**
	 * Musical instrument selling price.
	 */
	private double sellingPrice;
	
	/**
	 * Musical instrument amount rented.
	 */
	private int numberRented;
	
	/**
	 * Constructor: sets up an instance of the MusicalInstrument object.
	 * 
	 * @param description	Musical Instrument description.
	 * @param stockCode		Musical Instrument stock code (SKU).
	 * @param purchasePrice	Musical Instrument purchase price.
	 * @param sellingPrice	Musical Instrument selling price.
	 */
	public MusicalInstrument(String description, String stockCode, 
			double purchasePrice, double sellingPrice)
	{
		this.description = 		description;
		this.stockCode = 		stockCode;
		this.quantityInStock =	0;
		this.quantitySold = 	0;
		
		// Purchase price is greater than or equal to $1.00
		if(purchasePrice >= 1.00)
		{
			this.purchasePrice = purchasePrice;
		}
		else
		{
			this.purchasePrice = 1.00;
		}
		
		// Selling price is greater than or equal to 10% of purchase price
		if(sellingPrice >= 1.00 && sellingPrice >= (purchasePrice + 
				(purchasePrice * 0.1)))
		{
			this.sellingPrice = sellingPrice;
		}
		else
		{
			this.sellingPrice = 1.00 + (purchasePrice + (purchasePrice * 0.1));
		}
	}
	
	/**
	 * Accessor: musical instrument's description.
	 * 
	 * @return description
	 */
	public String getDescription()
	{
		return description;
	}
	
	/**
	 * Mutator: musical instrument's description.
	 * 
	 * @param description
	 */
	public void setDescription(String description)
	{
		this.description = description;
	}
	
	/**
	 * Accessor: musical instrument's stock code (SKU).
	 * 
	 * @return stockCode
	 */
	public String getStockCode()
	{
		return stockCode;
	}
	
	/**
	 * Mutator: musical instrument's stock code (SKU).
	 * 
	 * @param stockCode
	 */
	public void setStockCode(String stockCode)
	{
		this.stockCode = stockCode;
	}
	
	/**
	 * Accessor: musical instrument's quantity in stock.
	 * 
	 * @return quantityInStock
	 */
	public int getQuantityInStock()
	{
		return quantityInStock;
	}
	
	/**
	 * Mutator: musical instrument's quantity in stock.
	 * 
	 * @param quantityInStock
	 */
	public void setQuantityInStock(int quantityInStock)
	{
		this.quantityInStock = quantityInStock;
	}
	
	/**
	 * Accessor: musical instrument's quantity sold.
	 * 
	 * @return quantitySold
	 */
	public int getQuantitySold()
	{
		return quantitySold;
	}
	
	/**
	 * Mutator: musical instrument's quantity sold.
	 * 
	 * @param quantitySold 
	 */
	public void setQuantitySold(int quantitySold)
	{
		this.quantitySold = quantitySold;
	}
	
	/**
	 * Accessor: musical instrument's purchase price.
	 * 
	 * @return purchasePrice
	 */
	public double getPurchasePrice()
	{
		return purchasePrice;
	}
	
	/**
	 * Mutator: musical instrument's purchase price.
	 * 
	 * @param purchasePrice	Purchase price must be greater than or equal to
	 * 						$1.00.
	 */
	public void setPurchasePrice(double purchasePrice)
	{
		if(purchasePrice >= 1.00)
		{
			this.purchasePrice = purchasePrice;
		}
		else
		{
			System.err.println("Error: purchase price must be greater than"
					+ " or equal to $1.00.");
		}
	}
	
	/**
	 * Accessor: musical instrument's selling price.
	 * 
	 * @return sellingPrice
	 */
	public double getSellingPrice()
	{
		return sellingPrice;
	}
	
	/**
	 * Mutator: musical instrument's selling price.
	 * 
	 * @param sellingPrice 	Selling price must be greater than or equal to 10%
	 * 						of purchase price.
	 */
	public void setSellingPrice(double sellingPrice)
	{
		if(sellingPrice >= 1.00 && sellingPrice >= (purchasePrice + 
				(purchasePrice * 0.1)))
		{
			this.sellingPrice = sellingPrice;
		}
		else
		{
			System.err.println("Error: selling price must be greater than or"
					+ " equal to 10% of purchase price.");
		}
	}
	
	/**
	 * Accessor: musical instrument's amount rented.
	 * 
	 * @return numberRented
	 */
	public int getNumberRented()
	{
		return numberRented;
	}
	
	/**
	 * Mutator: musical instrument's amount rented.
	 * 
	 * @param numberRented
	 */
	public void setNumberRented(int numberRented)
	{
		if(numberRented <= quantityInStock)
		{
			this.numberRented = numberRented;
		}
		else
		{
			System.err.println("Error: number rented must be no more than " +
					"half the current inventory.");
		}
	}
	
	/**
	 * Mutator: musical instrument's quantity in stock after a restock.
	 * 
	 * @param quantityNewStock 	The amount of new stock. This will be added to
	 * 							the amount that is already currently in stock.
	 */
	public void restock(int quantityNewStock)
	{
		if(quantityNewStock >= 1)
		{
			this.quantityInStock = quantityInStock + quantityNewStock;
		}
		else
		{
			System.err.println("Error: you must restock with at least 1 new " +
					"item.");
		}
	}
	
	/**
	 * Mutator: musical instrument's quantity in stock and quantity sold after
	 * a sale.
	 * 
	 * @param amountSold 	The amount sold in the sale. This will be
	 * 						subtracted from the quantity in stock and
	 * 						added to the quantity sold.
	 */
	public void sell(int amountSold)
	{
		if(amountSold >= 0 && amountSold <= 50)
		{
			this.quantityInStock = quantityInStock - amountSold;
			this.quantitySold = quantitySold + amountSold;
		}
		else 
		if(amountSold < 0 || amountSold > 50)
		{
			System.err.println("Error: you cannot sell a negative number of"
					+ " items or too many items.");
		}
	}
	
	/**
	 * Calculate the profit made from selling a single instrument based on the
	 * selling price and purchase price.
	 * 
	 * @return the difference between the selling price and purchase price.
	 */
	public double calcProfit()
	{		
		return (sellingPrice - purchasePrice);
	}
	
	/**
	 * Calculate the total profit made by adding all of the single profits.
	 * 
	 * @return totalProfit The total profit made from the instrument.
	 */
	public double calcTotalProfit()
	{
		double totalProfit = 0.0;
		
		totalProfit = quantitySold * calcProfit();
		
		return totalProfit;
	}
	
	/**
	 * Calculates the inventory value of the instrument based on the purchase
	 * price.
	 * 
	 * @return the product of the quantity in stock and the purchase price.
	 */
	public double calcInventoryValue()
	{	
		return (quantityInStock * purchasePrice);
	}
	
	/**
	 * Prints information about the musical instrument to the console.
	 */
	public void printDetails()
	{
		NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance();
		
		System.out.println("Description: " + description);
		System.out.println("Stock code: " + stockCode);
		System.out.println("Purchase price: " + 
				currencyFormatter.format(purchasePrice));
		System.out.println("Selling price: " + 
				currencyFormatter.format(sellingPrice));
		System.out.println("Quantity in stock: " + quantityInStock);
		System.out.println("Inventory value: " + 
				currencyFormatter.format(calcInventoryValue()));
		System.out.println("Profit on sales: " + 
				currencyFormatter.format(calcTotalProfit())); 
		System.out.println("Number of instruments rented: " + numberRented);
	}
}
