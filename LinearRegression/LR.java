public abstract class LR {
    double Beta0;
    double Beta1;
    DataSet data;
    double Rsqr;
    Par par;
    double X;

    abstract void findBetas();

    abstract void Beta0();

    abstract void Beta1();

    abstract String ecuacionDeRegresion();

    abstract double findY(double X);

    abstract double findRsqr();

    abstract double getSSR();

    abstract double getSST();
}
