public class QLR extends LR{
    double Beta2;
    
    public QLR(DataSet data) {
        this.data = data;
    }

    public void findBetas(){
        Beta2();
        Beta1();
        Beta0();
        System.out.println(String.format("Beta0= %-5.4f | Beta1= %-5.4f | Beta2 =%-5.4f"
        ,Beta0,Beta1,Beta2));
    }

    void Beta0(){
        int n = this.data.getSize();
        this.Beta0 = (this.data.getSumY()/n)-(this.Beta1*(this.data.getSumX()/n))-(this.Beta2*((this.data.getSumX()/n)*(this.data.getSumX()/n)));        
    }

    void Beta1(){
        /*
         * b=((Sxy*Sx^2x^2)-(Sx^2y*Sxx^2))/((Sxx*Sx^2x^2)-(Sxx^2)^2)
         */
        double sum_xxy = this.data.getSumXXporY();
        double sum_xx = this.data.getSumXporX();
        double sum_xy = this.data.getSumXporY();
        double sum_xxx = this.data.getSumXporXX();
        double sum_xxxx = this.data.getSumXXporXX();
        this.Beta1 = ((sum_xy*sum_xxxx)-(sum_xxy*sum_xxx))/((sum_xx*sum_xxxx)-(sum_xxx*sum_xxx));
    }

    void Beta2(){
        /*
         * beta2 = ((Sx^2y*Sxx)-SxySxx^2)/(Sxx*Sx^2x^2-(Sxx^2)^2)
         */
        double sum_xxy = this.data.getSumXXporY();
        double sum_xx = this.data.getSumXporX();
        double sum_xy = this.data.getSumXporY();
        double sum_xxx = this.data.getSumXporXX();
        double sum_xxxx = this.data.getSumXXporXX();
        this.Beta2 = ((sum_xxy*sum_xx)-(sum_xy*sum_xxx))/((sum_xx*sum_xxxx)- (sum_xxx*sum_xxx));
    }

    public String ecuacionDeRegresion(){
        return String.format("^y = %.2f + %.2f*%.2f + %.2f*%.2f^2",this.Beta0,this.Beta1,this.X,this.Beta2,this.X);
    }

    public double findY(double X){
        this.X = X;
        double y = this.Beta0+this.Beta1*this.X+this.Beta2*(this.X*this.X);
        return y;
    }

    public double findRsqr(){        
        return 1-getSSR()/getSST();
    }

    
    double getSSR(){
        int n = this.data.getSize();
        double sse = 0.0;
        for(int i = 0; i < n; i++){
            double x = this.data.getAt(i).x;
            double dif = this.data.getAt(i).y-this.Beta0-this.Beta1*x-this.Beta2*x*x;
            sse += dif*dif;
        }
        return sse;
    }

    double getSST(){

        int n = this.data.getSize();
        double ymedia = this.data.getSumY()/n;
        double sst = 0;

        for(int i = 0; i < this.data.getSize(); i++){
            double dif = this.data.getAt(i).y-ymedia;
            sst += dif*dif;
        }

        return sst;
    }
}