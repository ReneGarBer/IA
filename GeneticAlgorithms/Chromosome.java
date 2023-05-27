import java.util.Random;

public class Chromosome {
    int[] chromosome = new int[20];
    int id;
    Chromosome(int id){
        createChromosome();
        this.id = id;
    }

    private void createChromosome(){
        Random rand = new Random();
        for (int i = 0; i < chromosome.length; i++) {
            chromosome[i] = rand.nextInt(2);
        }
    }

    public void printChromosome(){
        for(int c: chromosome){
            System.out.print(c);
        }
        System.out.println();
    }

    public int fitness(){
        int fit = 0;
        for(int c: chromosome){
            fit+= c;
        }
        return fit*5;
    }

    public void mutate(){
        Random random = new Random();
        int bit = random.nextInt(20);
        //chromosome[bit] = chromosome[bit] == 0? 1: 0;
        chromosome[bit] = 1;  
    }

    public int getAt(int i){
        return chromosome[i];
    }

    public void crossover(Chromosome parent1, Chromosome parent2){
        //Uniform crossover
        for(int i = 0; i < 20; i++){
            double Xi = Math.random();            
            if(Xi <0.5){
                this.chromosome[i] = parent1.chromosome[i];
            }else{
                this.chromosome[i] = parent2.chromosome[i];
            }
        }
    }
}
