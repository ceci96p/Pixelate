#include "stats.h"

	/* returns the sums of all pixel values across all color channels.
	* useful in computing the score of a rectangle
	* PA3 function
	* @param channel is one of r, g, or b
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){
		
		if (channel == 'r'){
			if(ul.first  == 0 && ul.second == 0){
				return sumRed[lr.second][lr.first];
			
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumRed[lr.second][lr.first] - sumRed[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumRed[lr.second][lr.first] - sumRed[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumRed[ul.second - 1][lr.first];
				long rec2 =  sumRed[lr.second][ul.first - 1];
				long addr_rec = sumRed[ul.second - 1][ul.first - 1];
				return (sumRed[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}

	    else if (channel == 'b'){
			if(ul.first  == 0 && ul.second == 0){
				return sumBlue[lr.second][lr.first];
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumBlue[lr.second][lr.first] - sumBlue[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumBlue[lr.second][lr.first] - sumBlue[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumBlue[ul.second - 1][lr.first]; 
				long rec2 =  sumBlue[lr.second][ul.first - 1];
				long addr_rec = sumBlue[ul.second - 1][ul.first - 1];
				return (sumBlue[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}

		else if (channel == 'g'){
			if(ul.first  == 0 && ul.second == 0){
				return sumGreen[lr.second][lr.first];
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumGreen[lr.second][lr.first] - sumGreen[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumGreen[lr.second][lr.first] - sumGreen[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumGreen[ul.second - 1][lr.first];
				long rec2 =  sumGreen[lr.second][ul.first - 1];
				long addr_rec = sumGreen[ul.second - 1][ul.first - 1];
				return (sumGreen[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}

		return 0;
	}
    	
	/* returns the sums of squares of all pixel values across all color channels.
	* useful in computing the score of a rectangle
	* PA3 function
	* @param channel is one of r, g, or b
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getSumSq(char channel, pair<int,int> ul, pair<int,int> lr){
		
		if (channel == 'r'){
			if(ul.first  == 0 && ul.second == 0){
				return sumsqRed[lr.second][lr.first];
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumsqRed[lr.second][lr.first] - sumsqRed[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumsqRed[lr.second][lr.first] - sumsqRed[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumsqRed[ul.second - 1][lr.first];
				long rec2 =  sumsqRed[lr.second][ul.first - 1];
				long addr_rec = sumsqRed[ul.second - 1][ul.first - 1];
				return (sumsqRed[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}

	    else if (channel == 'b'){
			if(ul.first  == 0 && ul.second == 0){
				return sumsqBlue[lr.second][lr.first];
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumsqBlue[lr.second][lr.first] - sumsqBlue[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumsqBlue[lr.second][lr.first] - sumsqBlue[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumsqBlue[ul.second - 1][lr.first]; 
				long rec2 =  sumsqBlue[lr.second][ul.first - 1];
				long addr_rec = sumsqBlue[ul.second - 1][ul.first - 1];
				return (sumsqBlue[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}

		else if (channel == 'g'){
			if(ul.first  == 0 && ul.second == 0){
				return sumsqGreen[lr.second][lr.first];
			}
			else if(ul.first == 0 && ul.second > 0){
				return sumsqGreen[lr.second][lr.first] - sumsqGreen[ul.second - 1][lr.first];
			}
			else if (ul.first > 0 && ul.second == 0){
				return sumsqGreen[lr.second][lr.first] - sumsqGreen[lr.second][ul.first - 1];
			}
			else if (ul.first > 0 && ul.second > 0){ 
				long rec1 =  sumsqGreen[ul.second - 1][lr.first]; 
				long rec2 =  sumsqGreen[lr.second][ul.first -1];
				long addr_rec = sumsqGreen[ul.second-1][ul.first-1];
				return (sumsqGreen[lr.second][lr.first] - rec1 - rec2) + addr_rec;
			}
		}
	
		return 0;
	}


	// initialize the private vectors so that, for each color,  entry 
	// (x,y) is the cumulative sum of the the color values from (0,0)
	// to (x,y). Similarly, the sumSq vectors are the cumulative
	// sum of squares from (0,0) to (x,y).
	stats::stats(PNG & im){
		

	/// resize vectors 
	sumRed.resize(im.height(), vector<long>(im.width()));
	sumGreen.resize(im.height(), vector<long>(im.width()));
	sumBlue.resize(im.height(), vector<long>(im.width()));

	sumsqRed.resize(im.height(), vector<long>(im.width()));
	sumsqGreen.resize(im.height(), vector<long>(im.width()));
	sumsqBlue.resize(im.height(), vector<long>(im.width()));

	for(unsigned int y = 0 ; y < im.height() ; y++){
	    for(unsigned int x = 0  ; x < im.width() ; x++) { 

	    	if (x == 0 && y == 0){
	    		sumRed[y][x] = im.getPixel(0,0)->r;
	    		sumGreen[y][x] = im.getPixel(0,0)->g;
	    		sumBlue[y][x] = im.getPixel(0,0)->b;

	    		sumsqRed[y][x] = (im.getPixel(0,0)->r) * (im.getPixel(0,0)->r);
	    		sumsqGreen[y][x] = (im.getPixel(0,0)->g) * (im.getPixel(0,0)->g);
	    		sumsqBlue[y][x] = (im.getPixel(0,0)->b) * (im.getPixel(0,0)->b);
	    	}

	    	else if (x > 0 && y == 0){
	    		sumRed[y][x] = (im.getPixel(x,0)->r) + sumRed[0][x-1];
	    		sumGreen[y][x] = (im.getPixel(x,0)->g) + sumGreen[0][x-1];
	    		sumBlue[y][x] = (im.getPixel(x,0)->b) + sumBlue[0][x-1];

	    		sumsqRed[y][x] = ((im.getPixel(x,0)->r) * (im.getPixel(x,0)->r)) + sumsqRed[0][x-1];
	    		sumsqGreen[y][x] = ((im.getPixel(x,0)->g) * (im.getPixel(x,0)->g)) + sumsqGreen[0][x-1];
	    		sumsqBlue[y][x] = ((im.getPixel(x,0)->b) * (im.getPixel(x,0)->b)) + sumsqBlue [0][x-1];
	    	}

	    	else if (x == 0 && y > 0){
	    		sumRed[y][x] = (im.getPixel(0,y)->r) + sumRed[y-1][0];
	    		sumGreen[y][x] = (im.getPixel(0,y)->g) + sumGreen[y-1][0];
	    		sumBlue[y][x] = (im.getPixel(0,y)->b) + sumBlue[y-1][0];

	    		sumsqRed[y][x] = ((im.getPixel(0,y)->r) * (im.getPixel(0,y)->r)) + sumsqRed[y-1][0];
	    		sumsqGreen[y][x] = ((im.getPixel(0,y)->g) * (im.getPixel(0,y)->g)) + sumsqGreen[y-1][0];
	    		sumsqBlue[y][x] = ((im.getPixel(0,y)->b) * (im.getPixel(0,y)->b)) + sumsqBlue[y-1][0];
	    	}

	    	else if (x > 0 && y > 0){
	    		sumRed[y][x] = ((im.getPixel(x,y)->r) + sumRed[y][x-1] + sumRed[y-1][x]) - sumRed[y-1][x-1];
	    		sumGreen[y][x] = ((im.getPixel(x,y)->g) + sumGreen[y][x-1] + sumGreen[y-1][x]) - sumGreen[y-1][x-1];
	    		sumBlue[y][x] = ((im.getPixel(x,y)->b) + sumBlue[y][x-1] + sumBlue[y-1][x]) - sumBlue[y-1][x-1];

	    		sumsqRed[y][x] = (((im.getPixel(x,y)->r) * (im.getPixel(x,y)->r)) + sumsqRed[y][x-1] + sumsqRed[y-1][x]) - sumsqRed[y-1][x-1];
	    		sumsqGreen[y][x] = (((im.getPixel(x,y)->g) * (im.getPixel(x,y)->g)) + sumsqGreen[y][x-1] + sumsqGreen[y-1][x]) - sumsqGreen[y-1][x-1];
	    		sumsqBlue[y][x] = (((im.getPixel(x,y)->b) * (im.getPixel(x,y)->b)) + sumsqBlue[y][x-1] + sumsqBlue[y-1][x]) - sumsqBlue[y-1][x-1];
	    	}
	    }
	}
}

	// given a rectangle, compute its sum of squared deviations from 
    // mean, over all color channels. Will be used to make split when
	// building tree.
	/* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getScore(pair<int,int> ul, pair<int,int> lr){
		
		long area = rectArea(ul,lr);

		long rr = getSumSq('r',ul,lr) - (((getSum('r',ul,lr) * getSum('r',ul,lr))) / area);

		long gg = getSumSq('g',ul,lr) - (((getSum('g',ul,lr) * getSum('g',ul,lr))) / area);

		long bb = getSumSq('b',ul,lr) - (((getSum('b',ul,lr) * getSum('b',ul,lr))) / area);

		return rr + gg + bb;
		
	}

	// given a rectangle, return the average color value over the 
	// rectangle as a pixel.
	/* Each color component of the pixel is the average value of that 
	* component over the rectangle.
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	RGBAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){
		
		long red = (getSum('r',ul,lr)/rectArea(ul,lr));
		long blue = (getSum('b',ul,lr)/ rectArea(ul,lr));
		long green = (getSum('g',ul,lr)/ rectArea(ul,lr));
	
		return RGBAPixel(red,green,blue); 

	}

	// given a rectangle, return the number of pixels in the rectangle
	/* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::rectArea(pair<int,int> ul, pair<int,int> lr){
		
		long x_val = (lr.first+1)-(ul.first);
		long y_val = (lr.second+1)-(ul.second);
		
		return (x_val * y_val);

	}


