import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class DataSet {
    /*
     * 
     * Constructor
     * To String
     * Insertar dato
     * eliminar dato
     * update dato 
     */
    private List<Par> dataset;

    public DataSet(List<Par> dataset) {
        this.dataset = dataset;
    }

    public void setDataset(List<Par> dataset) {
        this.dataset = dataset;
    }

    public int getSize(){
        return this.dataset.size();
    }

    public DataSet(int opc) {
        if(opc==1){
            this.dataset = new ArrayList<>();
            /*
             *             this.dataset.add(new Par(1,23,651));
            this.dataset.add(new Par(2,26,762));
            this.dataset.add(new Par(3,30,856));
            this.dataset.add(new Par(4,34,1063));
            this.dataset.add(new Par(5,43,1190));
            this.dataset.add(new Par(6,48,1298));
            this.dataset.add(new Par(7,52,1421));
            this.dataset.add(new Par(8,57,1440));
            this.dataset.add(new Par(9,58,1518));
             */
            this.dataset.add(new Par(1,1,3));
            this.dataset.add(new Par(2,2,6));
            this.dataset.add(new Par(3,3,9));
            this.dataset.add(new Par(4,4,12));
            this.dataset.add(new Par(5,5,15));
            this.dataset.add(new Par(6,6,18));
            this.dataset.add(new Par(7,7,21));
            this.dataset.add(new Par(8,8,24));
            this.dataset.add(new Par(9,9,27));
        }if(opc==2){
            this.dataset = new ArrayList<>();
            this.dataset.add(new Par(1,-3,7.5));
            this.dataset.add(new Par(2,-2,3));
            this.dataset.add(new Par(3,-1,0.5));
            this.dataset.add(new Par(4,0,1));
            this.dataset.add(new Par(5,1,3));
            this.dataset.add(new Par(6,2,6));
            this.dataset.add(new Par(7,3,14));
        }
    }

    public void add(Par par){
        this.dataset.add(new Par(par));
    }

    public void update(int index,Par par){
        this.dataset.set(0, new Par(par));
    }

    public void remove(int index) {
        this.dataset.remove(index);
    }

    public void sort(){
        Collections.sort(this.dataset);
    }

    public String toString(String Xcolumn,String Ycolumn){
        return toString("index", Xcolumn, Ycolumn);
    }

    public String toString(String indexName,String Xcolumn,String Ycolumn){
        
        StringBuilder tabla = new StringBuilder();
        
        tabla.append(String.format("%-5s %-10s %-10s%n", indexName,Xcolumn,Ycolumn));
        tabla.append("-------------------------------\n");

        int i = 1;

        for(Par par: this.dataset){
            tabla.append(String.format("%-5d %-10.2f %-10.2f%n", par.year,par.x,par.y));
            i++;
        }

        return tabla.toString();
    }

    public Par getAt(int pos){
        return this.dataset.get(pos);
    }

    double getSumXporX(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            double x = this.getAt(i).x;  
            sum += x*x;
        }
        return sum;
    }

    double getSumXporXX(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            double x = this.getAt(i).x;  
            sum += x*x*x;
        }
        return sum;
    }

    double getSumXXporXX(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            double x = this.getAt(i).x;  
            sum += x*x*x*x;
        }
        return sum;
    }

    double getSumXporY(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            sum += this.getAt(i).x*this.getAt(i).y;
        }
        return sum;
    }

    double getSumXXporY(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            double x = this.getAt(i).x;
            sum += (x*x)*this.getAt(i).y;
        }
        return sum;
    }

    double getSumY(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            sum += this.getAt(i).y;
        }
        return sum;
    }

    double getSumX(){
        double sum = 0;
        int n = this.getSize();
        for(int i = 0; i < n; i++){
            sum += this.getAt(i).x;
        }
        return sum;
    }
}
