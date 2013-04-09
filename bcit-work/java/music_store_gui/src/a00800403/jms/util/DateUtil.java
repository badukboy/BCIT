package a00800403.jms.util;

import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

/**
 * DateUtil.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class DateUtil {

	public static GregorianCalendar convertFromDMY(String dd_mm_yy) 
	{
		String[] elements = dd_mm_yy.split("-");
		
		if (elements == null || elements.length != 3) 
		{
			return null;
		}

		int year = Integer.parseInt(elements[2]);
		int month = Integer.parseInt(elements[1]) - 1; // GregorianCalendar
														// expects 0-based month
		int dayOfMonth = Integer.parseInt(elements[0]);
		GregorianCalendar date = new GregorianCalendar(year, month, dayOfMonth);
		
		return date;
	}

	public static String format(GregorianCalendar date) 
	{
		//DateFormat dateFormat = DateFormat.getDateInstance(DateFormat.MEDIUM);
		SimpleDateFormat dateString = new SimpleDateFormat("dd-MM-yyyy");

		return dateString.format(date.getTime());
	}
}
