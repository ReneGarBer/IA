import java.util.*;

public class Par implements Comparable<Par> {
    public double x;
    public double y;
    public int year;

    public Par(int year,double x, double y) {
        this.year = year;
        this.x = x;
        this.y = y;
    }

    public Par(Par par) {
        this.year = year;
        this.x = par.x;
        this.y = par.y;
    }

    @Override
    public int compareTo(Par par) {
        // Compare by x first, then by y
        int xDiff = Double.compare(this.x, par.x);
        if (xDiff != 0) {
            return xDiff;
        } else {
            return Double.compare(this.y, par.y);
        }
    }
}
