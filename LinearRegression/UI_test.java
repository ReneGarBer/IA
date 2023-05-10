import java.util.Scanner;

public class UI_test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean loop = true;
        LR lr;
        DataSet dataset;
        while (loop) {
            System.out.println("Seleccione una opcion:");
            System.out.println("1. Usar SLR");
            System.out.println("2. Usar QLR");
            System.out.println("3. Salir");
            int input = scanner.nextInt();
            switch (input) {
                case 1:
                    dataset = new DataSet(1);
                    lr = new SLR(dataset);
                    System.out.println("=======SLR=========");
                    System.out.println(dataset.toString("Año","Add investment (Million euro)","Revenue (Million euro)"));
                    lr.findBetas();
                    System.out.print("Valor de X: ");
                    double x = scanner.nextDouble();
                    System.out.println(String.format("Y= %-5f",lr.findY(x)));
                    System.out.println(lr.ecuacionDeRegresion());
                    System.out.println(String.format("R^2= %-5f",lr.findRsqr()));               
                    break;
                case 2:
                    dataset = new DataSet(2);
                    lr = new QLR(dataset);
                    DataSet dataset_lr = new DataSet(2);
                    System.out.println("=======QLR=========");
                    System.out.println(dataset_lr.toString("X","Y"));                    
                    lr.findBetas();
                    System.out.print("Valor de X: ");
                    x = scanner.nextDouble();
                    System.out.println(String.format("Y= %-5f",lr.findY(x)));
                    System.out.println(lr.ecuacionDeRegresion());
                    System.out.println(String.format("R^2= %-5f",lr.findRsqr()));
                    break;
                case 3:
                    System.out.println("Adios!");
                    loop = false;
                    break;
                default:
                    System.out.println("Seleccione una opcion valida");
                    break;
            }
            System.out.println("");
            System.out.println("");
        }
    }
}
