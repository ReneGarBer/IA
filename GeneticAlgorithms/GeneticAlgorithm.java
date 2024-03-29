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
        int id = population[parent1].id; 
        population[parent1] = optimalSolution;
        population[parent1].id = id;
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
            
        }
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
            population[i] = new Chromosome(i);
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
        System.out.printf("Parent 1. ID %d\n",parent1c.id);
        parent1c.printChromosome();
        System.out.printf("Parent 2. ID %d\n",parent2c.id);
        parent2c.printChromosome();
        System.out.printf("Children: ID %d\n",optimalSolution.id);
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