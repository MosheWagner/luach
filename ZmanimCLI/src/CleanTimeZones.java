

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.TimeZone;

/** CleanTimeZones
 * This class is used to generate an alphabetically sorted list of
 * available time zone IDs, that has less redundancy than the list
 * provided by TimeZone.getAvailableIDs().
 *
 * Three letter abbreviations are removed unless it is "UTC" or the
 * abbreviation has a unique set of time zone rules.
 *
 * US Time zones, and UTC, are moved to the top of the list. */

public class CleanTimeZones {

    /**
     * list, This holds our time zone list. It is generated only once per
     * application run. */
    static private String[] list = null;

    /** generateList
     * This is called to generate the times zone list. */
    @SuppressWarnings("unchecked")
    static private String[] generateList() {
// Get our starting list.
        ArrayList<String> startList =
                new ArrayList<String>(Arrays.asList(TimeZone.getAvailableIDs()));
        Collections.sort(startList);
// Loop through the available time zones, checking for possible deletions.
        for (Iterator<String> iter = startList.iterator(); iter.hasNext();) {
            String current = iter.next();

            ArrayList<String> als = (ArrayList<String>) (startList.clone());
            if (shouldDelete(current, als)) {
                iter.remove();
            }
        }
// Move anything starting with the letter "U" to the top of the list.
        ArrayList<String> uList = new ArrayList<String>();
        for (Iterator<String> iter = startList.iterator(); iter.hasNext();) {
            String current = iter.next();
            if (current.toLowerCase().startsWith("u")) {
                uList.add(current);
                iter.remove();
            }
        }
        for (int i = (uList.size() - 1); i >= 0; --i) {
            startList.add(0, uList.get(i));
        }

        return startList.toArray(new String[0]);
    }

    /** get
     * Call this to get the cleaned list of time zones. */
    static public String[] get() {
        if (list == null) {
            list = generateList();
        }
        return list;
    }

    /** shouldDelete
     * This is called to determine if a time zone should be deleted. */
    static private boolean shouldDelete( String zoneString, ArrayList<String> copyOfRemainingList) {
// Define a list of duplicate zones that you want to remove.
        String[] deleteZones = new String[]{
            "Etc/Greenwich", "Etc/UCT", "Etc/UTC", "Etc/Universal", "Etc/Zulu",
            "Zulu", "Etc/GMT-0", "Etc/GMT0", "GMT0", "Greenwich", "Universal"
        };
// Define a list of zone prefixes that you wish to keep.
        String[] protectedPrefixes = new String[]{
            "UTC", "US/"
        };
// Get the time zone instance from the zone string.
        TimeZone zone = TimeZone.getTimeZone(zoneString);
// Calculate how many copies remain in the list.
        int copies = 0;
        for (String remainingString : copyOfRemainingList) {
            TimeZone remainingZone = TimeZone.getTimeZone(remainingString);
            if (remainingZone.hasSameRules(zone)) {
                ++copies;
            }
        }
// Remove all zones listed in deleteZones that are duplicates.
        for (String delete : deleteZones) {
            if (zoneString.equalsIgnoreCase(delete) && copies > 1) {
                return true;
            }
        }
// Keep all protected prefixes.
        for (String protect : protectedPrefixes) {
            if (zoneString.toLowerCase().startsWith(protect.toLowerCase())) {
                return false;
            }
        }
// Remove all three letter zones that are duplicates.
        if (zoneString.length() == 3 && copies > 1) {
            return true;
        }
        return false;

    }

    /** showDuplicates
     * This can be used to see which time zones have duplicate values and
     * daylight savings time rules. */
    static public void showDuplicates(String[] zoneList) {
        ArrayList<String> all =
                new ArrayList<String>(Arrays.asList(zoneList));
        Collections.sort(all);
        for (String first : all) {
            int copies = 0;
            TimeZone firstZone = TimeZone.getTimeZone(first);
            for (String second : all) {
                TimeZone secondZone = TimeZone.getTimeZone(second);
                if (firstZone.hasSameRules(secondZone)) {
                    ++copies;
                }
            }
        }
    }
} 
