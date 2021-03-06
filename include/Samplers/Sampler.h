#ifndef __SAMPLER_H__
#define __SAMPLER_H__
#include "Utilities/Point2D.h"
#include <vector>
#define DEFAULT_NUM_SETS 83
class Sampler
{
public:
   Sampler(int num_samples, int num_sets = DEFAULT_NUM_SETS);

   Sampler(const Sampler & other);

   virtual Sampler * clone() const = 0;

   virtual ~Sampler();



   virtual void generate_samples() = 0;

   //Set up the shuffled indicies
   void setup_shuffled_indices();

   //Shuffle the samples in each sampler
   void shuffle_samples();

   int get_num_samples() const;

   void set_num_samples() const;

   void set_num_samples(const int num_samples);
   //Get the next point in the sampler
   Point2D sample_unit_square();
protected:

   int num_samples; //Samples per pattern
   int num_sets; //patterns in sampler
   std::vector<Point2D> samples; //Samples in the square
   std::vector<int> shuffled_indices; // Number of indicies
   unsigned long count; // Number of sample points used
   int jump;

private:
   bool initializedSamples = false;
};
#endif