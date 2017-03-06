#include <stdio.h>
int main()
{
	
	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
	
	char * commandsForGnuplot[] = {"set terminal png","set output 'desc_ibsr.png'","set xlabel 'Input Size'","set ylabel 'Time taken (in s)'","plot 'output_ins_desc.txt' using 1:2 with lines title 'Insertion','output_bub_desc.txt' using 1:2 with lines title 'Bubble', 'output_rank_desc.txt' using 1:2 with lines title 'Rank', 'output_sel_desc.txt' using 1:2 with lines title 'Selection'"};
	for (int i=0; i <5; i++)
    	{
    	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    	}	
}