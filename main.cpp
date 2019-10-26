
// File:        main.cpp
// Author:      cheeren
// Date:        2018-02-25
// Description: Partial test of PA3 functionality
//              Reads Point data from external files
//              Produces PNG images of the point sets


#include "twoDtree.h"
#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

using namespace cs221util;
using namespace std;

int main()
{

	// read in image
	PNG origIm1;
	origIm1.readFromFile("images/stanley-totem-poles.png");
	PNG origIm2;
	origIm2.readFromFile("images/ubc-totem-poles.png");
	PNG origIm3;
	origIm3.readFromFile("images/remb.png");
	PNG origIm4;
	origIm4.readFromFile("images/rosa.png");

	//PNG copy; 
	/*copy.readFromFile("images/square.png");
	copy.resize(2,2);
	copy.writeToFile("images/resized.png");
	twoDtree tcopy(copy);
	twoDtree tcopycopy(tcopy);
	PNG piccopy = tcopycopy.render();
	piccopy.writeToFile("images/copycopy.png");*/
	
	//copy.writeToFile("images/2by2.png");

	/*PNG trial;
	trial.readFromFile("images/trial-img.png");
	twoDtree trial_orig(trial);
	twoDtree trial_copy(trial_orig);
	trial_copy.prune(0.95, 10000);
	PNG ttt = trial_copy.render();
	ttt.writeToFile("images/trial_to_render.png");*/


/*
	std::pair <int,int> one = make_pair(0 , 0);
	std::pair <int,int> two = make_pair(0 , 1);
	std::pair <int,int> three = make_pair(0 , 2);
	std::pair <int,int> four = make_pair(1 , 0);
	std::pair <int,int> five = make_pair(2 , 0);
	std::pair <int,int> six = make_pair(1 , 1);
	std::pair <int,int> seven = make_pair(2 , 2);
	//stats(copy).getScore(ul,lr);
	//stats(copy).getAvg(ul,lr);

	stats(origIm1).getScore(one,one);   //0,0 && 0,0
	stats(origIm1).getScore(two,two);   //0,1 && 0,1
	stats(origIm1).getScore(four,four); //1,0 && 1,0
	stats(origIm1).getScore(six,six);   //1,1 && 1,1


	stats(origIm1).getScore(one,two);  //0,0 && 0,1
	stats(origIm1).getScore(one,four); //0,0 && 1,0
	stats(origIm1).getScore(six,six); //0,0 && 1,0


	stats(origIm1).getScore(one,six);  //0,0 && 1,1
*/

	// use it to build a twoDtree
	twoDtree t1(origIm1);
	twoDtree tCopy1(t1);
	twoDtree t2(origIm2);
	twoDtree tCopy2(t2);
	twoDtree t3(origIm3);
	twoDtree tCopy3(t3);
	twoDtree t4(origIm4);
	twoDtree tCopy4(t4);



	// prune the twoDtree
	//where at least 100*X% of pixels are within Y of mean
	tCopy1.prune(0.95, 10000); 
	tCopy2.prune(0.95, 10000); 
	tCopy3.prune(0.95, 3000); 
	tCopy4.prune(0.95, 3000); 
	/*tCopy1.prune(1.0, 10000); 
	tCopy2.prune(1.0, 10000); 
	tCopy3.prune(1.0, 3000); 
	tCopy4.prune(1.0, 3000);*/



    //render twoDtree
    
    PNG pic1 = tCopy1.render();
    PNG pic2 = tCopy2.render();
    PNG pic3 = tCopy3.render();
    PNG pic4 = tCopy4.render();
  

    pic1.writeToFile("images/stanleytotem_buildtree.png");
    pic2.writeToFile("images/ubctotem_buildtree.png");
    pic3.writeToFile("images/remb_buildtree.png");
    pic4.writeToFile("images/rosa_buildtree.png");




	// render the twoDtree
	/*PNG ppic1 = tCopy1.render();
	PNG ppic2 = tCopy2.render();
	PNG ppic3 = tCopy3.render();
	PNG ppic4 = tCopy4.render();

	ppic1.writeToFile("images/prunedstanleytotem.png");
	ppic2.writeToFile("images/prunedubctotem.png");
	ppic3.writeToFile("images/prunedremb.png");
	ppic4.writeToFile("images/prunedrosa.png");*/

}

