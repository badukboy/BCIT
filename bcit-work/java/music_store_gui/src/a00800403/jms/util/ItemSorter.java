package a00800403.jms.util;

import java.util.Comparator;

import a00800403.jms.data.MusicalInstrument;

/**
 * ItemSorter.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class ItemSorter 
{
	public static class SortByDescription implements Comparator<MusicalInstrument> 
	{
		public int compare(MusicalInstrument arg0, MusicalInstrument arg1) 
		{
			String description0 = arg0.getDescription() == null ? "" : arg0.getDescription();
			String description1 = arg1.getDescription() == null ? "" : arg1.getDescription();
			
			return description0.compareToIgnoreCase(description1);
		}
	}

	public static class SortByPrice implements Comparator<MusicalInstrument> 
	{
		public int compare(MusicalInstrument arg0, MusicalInstrument arg1)
		{
			String price0 = String.valueOf(arg0.getSellingPrice());
			String price1 = String.valueOf(arg1.getSellingPrice());
			
			return price0.compareTo(price1);
		}
	}
}
