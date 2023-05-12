public class GeneticAlgorithm {
    Chromosome[] population = new Chromosome[100];
    double[] selectionProbability= new double[100];
    Chromosome optimalSolution;
    Chromosome parent1c;
    Chromosome parent2c;
    int opt_sol_index;
    int parent1;
    int parent2;
    double mutationRate;
    double crossoverRate;
    int genCount = 0;

    GeneticAlgorithm(){
        this.mutationRate = 0.8;
        this.crossoverRate = 0.9;
        fillPopulation();
        setOptimalSolution();
    }

    public void findOptimalSolution(){
        do{
            rouletteWheel();
            crossover();
            mutation();
            //elitism();
            replace();
            printResults();

            genCount++;
        }while(!fitness());
        printResults();
    }

    private void replace() {

        population[parent1] = optimalSolution;
    }

    private void rouletteWheel(){
        
        int totalFitness = getTotalFitness();
        for(int i = 0; i < 100; i++){
            selectionProbability[i] = (double)population[i].fitness()/totalFitness;
        }

        double spin1 = Math.random(); 
        double partialSum = 0;
        for(int i = 0; i < 100; i++){
            partialSum+=selectionProbability[i];
            if(partialSum>=spin1){
                parent1 = i;
                parent1c = population[i];
                break;
            }
        }

        partialSum = 0;
        double spin2 = Math.random();         
        for(int i = 0; i < 100; i++){
            partialSum+=selectionProbability[i];
            if(partialSum>=spin2 && i != parent1){
                parent2 = i;
                parent2c = population[i];
                break;
            }
        }
        try {
            Thread.sleep(250);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            //e.printStackTrace();
        }
        //System.out.printf("spin1: %f%nspin1: %f%n",spin1,spin2);
    }

    private boolean fitness(){
        return optimalSolution.fitness()==100;
    }

    public void printOptimalSolution(){
        population[opt_sol_index].printChromosome();
    }

    public void printPopulation(){
        for(Chromosome c : population){
            c.printChromosome();
            System.out.println();
        }
    }

    private void fillPopulation(){
        for(int i = 0; i < 100; i++){
            population[i] = new Chromosome();
        }
    }

    private int getTotalFitness(){
        int total=0;
        
        for(Chromosome c : population){
            total+=c.fitness();
        }

        return total;
    }

    private void setOptimalSolution(){
        optimalSolution = population[0];
        for(Chromosome c : population){
            if(optimalSolution.fitness() < c.fitness())
                optimalSolution = c;
        }
    }

    private void crossover(){
        double x = Math.random();
        if(x <= crossoverRate){
            optimalSolution.crossover(parent1c,parent2c);            
        }
    }

    private void mutation(){
        double x = Math.random();            
        if(x <= mutationRate){
            optimalSolution.mutate();
        }
    }

    private void printResults(){
        System.out.println("Generation: "+genCount);
        System.out.println("Parent 1: ");
        parent1c.printChromosome();
        System.out.println("Parent 2: ");
        parent2c.printChromosome();
        System.out.println("Children: ");
        optimalSolution.printChromosome();
    }

    private void elitism(){
        int j = 0;
        for(int i = 0; i < 100; i++ ){
            if(population[j].fitness() > population[i].fitness())
                j = i;
        }
        population[j] = optimalSolution;
    }
}
