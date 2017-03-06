#include <stdio.h>
int main()
{
	
	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
	
	char * commandsForGnuplot[] = {"set terminal png","set output 'desc_mq.png'","set xlabel 'Input Size'","set ylabel 'Time taken (in s)'","plot 'output_qui_desc.txt' using 1:2 with lines title 'Quick','output_mer_desc.txt' using 1:2 with lines title 'Merge'"};
	for (int i=0; i <5; i++)
    	{
    	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    	}	
}