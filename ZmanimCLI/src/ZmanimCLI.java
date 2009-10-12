/*
*  ZmanimCLI - Simple Command Line Interface for the Zmanim API.
*  
*  Created by Moshe Wagner (moshe.wagner@gmail.com)
*
*  ZmanimCLI, and the Zmanim API programs are free software:
*  you can redistribute it and/or modify  them under the terms of the GNU General Public License
*  as published by the Free Software Foundation, either version 2 of the License, or
*  (at your option) any later version.

*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.

*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

import java.awt.List;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.TimeZone;

import net.sourceforge.zmanim.ComplexZmanimCalendar;
import net.sourceforge.zmanim.ZmanimCalendar;
import net.sourceforge.zmanim.util.GeoLocation;

public class ZmanimCLI {

	
	//TODO:
	// Add comments :-)
	
	
    public static void main(String[] args) 
    {
    	
    	//Make sure we got arguments
    	if ( args.length == 0 ) printUsage();

    	
    	//Default settings are for Jerusalem, Israel
    	
        TimeZone timeZone = TimeZone.getTimeZone("Israel");
        //קו רוחב
        double latitude = 31.77805;
        //קו אורך
        double longitude = 35.235149;
        //גובה. אם הוא שלילי הוא לא רלוונטי, ויש לשים 0
        double elevation = 700;
        
		Date date = new Date();
        
        //The function that should be called
		Method method = null;
    	
		//Loop over given arguments
    	for (int i=0; i<args.length; i ++)
    	{	
    		//Print help
    		if (args[i].compareTo("-h") == 0 || args[i].compareTo("--help") == 0)
			{
    			printUsage();
			}
    		
    		//Print a list of the available time zones
    		else if (args[i].compareTo("--timezone-list") == 0 || args[i].compareTo("-tzl") == 0)
			{
    			String [] timezones = CleanTimeZones.get();
    			System.out.println("List of valid TimeZones:");
    			for (int j=0; j<timezones.length; j++)
    			{
	    			System.out.println( timezones[j] );
				}
    			System.exit(0);
			}
    		
    		//Print a full list of the available functions to call
    		else if (args[i].compareTo("--full-time-list") == 0 || args[i].compareTo("-ftl") == 0)
			{
    	    	Method[] M = ComplexZmanimCalendar.class.getMethods();
    	    	for (int j=0; j<M.length; j++)
    	    	{
    	    		if ( M[j].getReturnType() == Date.class)
    	    		{
    	    			int p = M[j].toString().indexOf("get");
    	    			if (p != -1)
    	    				System.out.println( M[j].toString().substring(p+3, M[j].toString().length()-2));
    	    		}
	    		}
    	    	System.exit(0);
			}
    		
    		//Print a list of the common available functions to call
    		else if (args[i].compareTo("--time-list") == 0 || args[i].compareTo("--simple-time-list") == 0 || args[i].compareTo("-stl") == 0)
			{
    	    	Method[] M = ZmanimCalendar.class.getMethods();
    	    	for (int j=0; j<M.length; j++)
    	    	{
    	    		if ( M[j].getReturnType() == Date.class)
    	    		{
    	    			int p = M[j].toString().indexOf("get");
    	    			if (p != -1)
    	    				System.out.println( M[j].toString().substring(p+3, M[j].toString().length()-2));
    	    		}
	    		}
    	    	System.exit(0);
			}
    		
    		
    		
    		//latitude setting
    		else if ( args[i].compareTo("--latitude") == 0 || args[i].compareTo("-lat") == 0)
    		{
    			if (i+1 >= args.length) printUsage();
    			
    			if (checklatitude(args[i+1]) == true)
    	            latitude = Double.parseDouble(args[i+1]);
    			else
    			{
    				System.out.println("Latitude must be between -90 and 90!");
    				System.exit(2);
    			}
    			
    			i++;
    		}
    		
    		//longitude setting
    		else if ( args[i].compareTo("--longitude") == 0 || args[i].compareTo("-lon") == 0)
    		{
    			if (i+1 >= args.length) printUsage();
    			
    			if (checklongitude(args[i+1]) == true)
    				longitude = Double.parseDouble(args[i+1]);
    			else
    			{
    				System.out.println("Longitude must be between -180 and 180!");
    				System.exit(2);
    			}
    			
    			i++;
    		}
    		
    		//date setting
    		else if ( args[i].compareTo("--date") == 0 || args[i].compareTo("-d") == 0)
    		{
    			if (i+1 >= args.length) printUsage();
    			
    			SimpleDateFormat formatter = new SimpleDateFormat("yyyy/MM/dd");
    			
    			try 
    			{
					date = formatter.parse(args[i+1]);
				} 
    			catch (ParseException e) {
    				System.out.println("Invalid date!");
    				System.exit(6);
				}
    			
    			i++;
    		}
    		
    		//elevation setting
    		else if ( args[i].compareTo("--elevation") == 0 || args[i].compareTo("-e") == 0)
    		{
    			if (i+1 >= args.length) printUsage();
    			
    			if (ispositivedouble(args[i+1]))
					elevation = Double.parseDouble(args[i+1]);
    			else
    			{
    				System.out.println("Elevation must be positive! Using 0 instead...");
    			}
    			
    			i++;
    		}
    		
    		//TimeZone setting
    		else if ( args[i].compareTo("--timezone") == 0 || args[i].compareTo("-tz") == 0)
    		{
    			if (i+1 >= args.length) printUsage();
    			
    			if (Arrays.asList(TimeZone.getAvailableIDs()).contains(args[i+1]))
    			{
    				timeZone = TimeZone.getTimeZone(args[i+1]);
    			}
    			else
    			{
    				System.out.println("Invalid TimeZone! using default (Israel)");
    			}
    			
    			i++;
    		}
    		
    		
    		//Time function to show
    		else 
    		{
    			String om;
    			
    			if ( args[i].compareTo("--time") == 0)
    			{
	    			if (i+1 >= args.length) printUsage();
	    			
	    			 om = args[i+1];
	    			 
	    			 i++;
    			}
    			else om = args[i];		
    			
    			method = methodFromName(om);
    			
    		}
    		
    	}
    	
    	GeoLocation location = new GeoLocation("", latitude, longitude, elevation, timeZone);
    	
    	ComplexZmanimCalendar czc =  new ComplexZmanimCalendar(location);
    	
    	Calendar c = czc.getCalendar();
    	c.setTime(date);
    	czc.setCalendar(c);
    	
    	//Print the requested time
    	if (method != null)
    	{
    		try 
    		{
    			//This is safe because we checked it's a date function earlier
    			System.out.println( TimeOfDay( (Date) method.invoke(czc)) );
    			//System.out.println(  method.invoke(czc) );
    		} 
    		catch (IllegalArgumentException e) {} 
    		catch (IllegalAccessException e) {} 
    		catch (InvocationTargetException e) {}
		}
    	else
    	{
    		
    		//TODO: Improve usage!
    		System.out.println("No requested time given... Printing standard list:");
    		
    		//Print the times I use:
    		List times = new List();
    		times.add("AlosHashachar");
    		times.add("sunrise"); 
    		times.add("SofZmanShmaMGA");
    		times.add("SofZmanShmaGRA");
    		times.add("SofZmanTfilaMGA");
    		times.add("SofZmanTfilaGRA");
    		times.add("Chatzos");
    		times.add("MinchaGedola");
    		times.add("MinchaKetana");
    		times.add("PlagHamincha");
    		times.add("Sunset");
    		times.add("Tzais");
    		times.add("Tzais72");
    		
    		for (int i =0; i<times.getItemCount(); i++)
    		{
    			Method m = null;
    			m = methodFromName(times.getItem(i));
    			
    			if (m != null)
    			{
	        		try 
	        		{
	        			//This is safe because we checked it's a date function earlier
	        			System.out.println( "* " + times.getItem(i) + ": " + TimeOfDay( (Date) m.invoke(czc)) );
	        			//System.out.println(  method.invoke(czc) );
	        		} 
	        		catch (IllegalArgumentException e) {} 
	        		catch (IllegalAccessException e) {} 
	        		catch (InvocationTargetException e) {}
    			}
    			else
    				System.out.println( "Bad time " +  times.getItem(i));
    		}
    	}
    }
    
    
    //Print program's help and quit
    public static void printUsage()
    {
		System.out.println( "Usage: ZmanimCLI [options] [Time]" );
		System.out.println();
		
		System.out.println( "Options:" );
		System.out.println( "	-d 	--date <yyyy/mm/dd>		Set date. (Year first!)" );
		System.out.println( "	-lat 	--latitude <latitude>		Set location's latitude" );
		System.out.println( "	-lon 	--longitude <longitude>		Set location's longitude" );
		System.out.println( "	-e 	--elevation <elevation>		Set location's elevation; Positive only" );
		System.out.println( "	-tz 	--timezone <timezone>		Set location's TimeZone" );
		System.out.println();
		
		System.out.println( "Help:" );
		System.out.println( "	-h 	--help				Show this help" );
		System.out.println( "	-stl 	--time-list  			Show common available times to display" );
		System.out.println( "	-ftl 	--full-time-list 		Show all available times to display" );
		System.out.println( "	-tzl 	--timezone-list			Show available timezones" );
		System.out.println();
		
		System.out.println( "Exapmle:" );
		System.out.println( "	ZmanimCLI --latitude 31.7780 --longitude 35.235149 --elevation 600 --timezone Israel Sunrise" );
		System.out.println( "	Will show the sunrise time today in Jerusalem" );
		System.exit(1);
    }
	
    
    
    private static boolean ispositivedouble(String doub) {
        double number;
        try
        {
            number = Double.parseDouble(doub);
            if (number < 0)
                return false;
        }
        catch(NumberFormatException nfe)
        {
             return false;
        }
        return true;
    }

    private static boolean checklatitude(String lat)
    {
        double latitude;
        try
        {
            latitude = Double.parseDouble(lat);
            if ((latitude > 90) || (latitude <  -90) )
                return false;
        }
        catch(NumberFormatException nfe)
        {
             return false;
        }
        return true;
    }

    private static boolean checklongitude(String lng) {
        double longitude;
        try
        {
            longitude = Double.parseDouble(lng);
            if ((longitude > 180) || (longitude < -180))
                return false;
        }
        catch(NumberFormatException nfe)
        {       
        	return false;
        }
        return true;
    }  
	
    //Returns a string representing the given date
    private static String TimeOfDay(java.util.Date date)
    {
        if(date != null)
        {
            GregorianCalendar gc = new GregorianCalendar();
            String Time="";

            int hour, minute,second;

            gc.setTime(date);
            hour = gc.get(GregorianCalendar.HOUR_OF_DAY);


            minute =  gc.get(GregorianCalendar.MINUTE);
            second = gc.get(GregorianCalendar.SECOND);

            Time =Integer.toString(hour) + ":" +  StringifyTwoDigits(minute) + ":" +  StringifyTwoDigits(second);

            return Time;
        }
        //In some places some time are not available every day, so "N/A" is shown.
            //(I.E. , in Alaska there isn't sunrise and sunset every day.)
        else
            return "N/A";
    }
    
    //Returns a string representing the given number, with at least 2 digits (a "0" is added if neded)
    private static String StringifyTwoDigits(int num)
    {
        String str = "";
        str = Integer.toString(num);
        if (str.length() == 1)
            str = "0" + Integer.toString(num);
        return str;
    }
    
    private static Method methodFromName(String name)
    {
    	String m;
    	
		//Capitalize first letter
		m = name.substring(0, 1).toUpperCase() + name.substring(1);
		
		if (m.startsWith("get") == false) m = "get" + m;
		
		try 
		{
			return ComplexZmanimCalendar.class.getMethod(m);
		} 
		catch (SecurityException e) {}
		catch (NoSuchMethodException e) 
		{
			System.out.println("Invalid time or option: \"" +  name + "\"!");
			System.exit(4);
		}
		
		return null;
    
    }
}
