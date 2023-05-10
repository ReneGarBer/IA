public class SLR extends LR{

    public SLR(DataSet data) {
        this.data = data;
    }

    public void findBetas(){
        Beta1();
        Beta0();
        System.out.println(String.format("Beta0= %-5.2f | Beta1=%-5.2f",Beta0,Beta1));
    }

    void Beta0(){
        /*
         * =(sumatoria_y-beta1*sumatoria_x)/n
         */
        this.Beta0 = (this.data.getSumY()-this.Beta1*this.data.getSumX())/this.data.getSize();        
    }

    void Beta1(){
        /*
         * (n*sumatoria_de_x_por_y-sumatoria_de_x*sumatoria_de_y)/(n*sumatoria_de_x_cuadrada-sumatoria_de_x*sumatoria_de_x)
         */
        int n = this.data.getSize();
        double sum_x = this.data.getSumX();
        double sum_y = this.data.getSumY();
        double sum_xsqr = this.data.getSumXporX();
        double sum_xy = this.data.getSumXporY();

        this.Beta1 = (n*sum_xy-sum_x*sum_y)/(n*sum_xsqr-sum_x*sum_x);
    }

    public String ecuacionDeRegresion(){
        return String.format("^y = %f + %f * %f",this.Beta0,this.Beta1,this.X);
    }

    public double findY(double X){
        this.X = X;
        double y = this.Beta0+this.Beta1*this.X;
        return y;
    }

    public double findRsqr(){        
        return 1-getSSR()/getSST();
    }
    
    double getSSR(){
        int n = this.data.getSize();
        double ssr = 0.0;
        for(int i = 0; i < n; i++){
            double yopt = findY(this.data.getAt(i).x);
            double dif = this.data.getAt(i).y-yopt;
            ssr += dif*dif;
        }
        return ssr;
    }

    double getSST(){

        int n = data.getSize();
        double ymedia = this.data.getSumY()/n;
        double sst = 0;

        for(int i = 0; i < data.getSize(); i++){
            double dif = data.getAt(i).y-ymedia;
            sst += dif*dif;
        }

        return sst;
    }
}
