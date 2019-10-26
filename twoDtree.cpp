
/**
 *
 * twoDtree (pa3)
 * slight modification of a Kd tree of dimension 2.
 * twoDtree.cpp
 * This file will be used for grading.
 *
 */

#include "twoDtree.h"
#include <iostream>

/* given */
twoDtree::Node::Node(pair<int,int> ul, pair<int,int> lr, RGBAPixel a)
	:upLeft(ul),lowRight(lr),avg(a),left(NULL),right(NULL)
	{}

/* given */
twoDtree::~twoDtree(){
	clear();
}

/* given */
twoDtree::twoDtree(const twoDtree & other) {
	copy(other);
}

/* given */
twoDtree & twoDtree::operator=(const twoDtree & rhs){
	if (this != &rhs) {
		clear();
		copy(rhs);
	}
	return *this;
}

twoDtree::twoDtree(PNG & imIn){ //revise if stats object is created in the call to buildtree
	
	std::pair <int,int> ul = make_pair(0,0);  
	std::pair <int,int> lr = make_pair(imIn.width()-1,imIn.height()-1); 

	stats s = imIn;
	height = imIn.height();
	width = imIn.width();
	
	root = buildTree(s,ul,lr);
}

twoDtree::Node * twoDtree::buildTree(stats & s, pair<int,int> ul, pair<int,int> lr) {
 Node* r = new Node(ul, lr, s.getAvg(ul,lr));
   build_rec(s, ul, lr, r);
   return r;
}

void twoDtree::build_rec(stats & s, pair<int,int> ul, pair<int,int> lr, Node* & node){
if ((ul.first == lr.first) && (ul.second == lr.second)){ //base case
	 	return;
	}	 
	//split to then recursively fill in the nodes
	long score_h = -1;
	long score_v = -1;

	std::pair <int,int> left_h;
	std::pair <int,int> right_h;

	std::pair <int,int> left_v;
	std::pair <int,int> right_v;

if(lr.second > ul.second){
	//check horizontal 
	for (int i = ul.second + 1 ; i <= (lr.second); i++){
		std::pair <int,int> it1 = make_pair(lr.first , i - 1);
		std::pair <int,int> it2 = make_pair(ul.first , i);

		if (i == ul.second + 1){
			score_h = s.getScore(ul,it1) + s.getScore(it2, lr);
			left_h = it1;
			right_h = it2;

		}

		else if (s.getScore(ul,it1) + s.getScore(it2, lr) < score_h){
			score_h = s.getScore(ul,it1) + s.getScore(it2, lr);
			left_h = it1;
			right_h = it2;
		}
	}	
}

if(lr.first > ul.first){
	//check vertical	
	for (int i = ul.first + 1 ; i <= (lr.first) ; i++){
		std::pair <int,int> it1 = make_pair(i - 1, lr.second);
		std::pair <int,int> it2 = make_pair(i     ,ul.second);

		if (i == ul.first + 1){
			score_v = s.getScore(ul,it1) + s.getScore(it2, lr);
			left_v = it1;
			right_v = it2;
		}

		else if (s.getScore(ul,it1) + s.getScore(it2, lr) < score_v){
			score_v = s.getScore(ul, it1) + s.getScore(it2, lr);
			left_v = it1;
			right_v = it2;
		}
	}

}

if (score_h == -1|| score_v == -1){
	if (score_h == -1){
        node->left = new Node(ul,left_v,s.getAvg(ul,left_v));
        node->right = new Node(right_v, lr,s.getAvg(right_v,lr));
		 build_rec(s,ul,left_v,node->left);
		 build_rec(s,right_v, lr,node->right);
	}
	else if (score_v == -1){   
	    node->left = new Node(ul, left_h,s.getAvg(ul,left_h));
        node->right = new Node(right_h,lr, s.getAvg(right_h,lr) );              
		build_rec(s,ul,left_h,node->left);
	    build_rec(s,right_h, lr,node->right);
	}
}

else{
    if(score_h > score_v){       //recursion for  building nodes over vertical split
    	node->left = new Node(ul,left_v,s.getAvg(ul,left_v));
        node->right = new Node(right_v, lr,s.getAvg(right_v,lr));

	    build_rec(s,ul,left_v,node->left);
		build_rec(s,right_v, lr,node->right);
	}
	else if (score_h <= score_v){  //recursion for building nodes over horizontal split
		node->left = new Node(ul, left_h,s.getAvg(ul,left_h));
        node->right = new Node(right_h,lr, s.getAvg(right_h,lr) );              
	    build_rec(s,ul,left_h,node->left);
	    build_rec(s,right_h, lr,node->right);
	}
}
}

PNG twoDtree::render(){
PNG im(width,height);
render_recur(im, root);
return im;
}


void twoDtree::render_recur(PNG & im, Node*  node){
    if (node == NULL){
    	return;
    }
    if ((node->left == NULL) && (node->right == NULL)){

        for(long y = node->upLeft.second; y<= node->lowRight.second; y++){
        	for (long x = node->upLeft.first; x<= node->lowRight.first; x++){
        	
				RGBAPixel *pixel = im.getPixel(x, y);
				
				*pixel = node->avg;
        	}
    	}
    }
    render_recur(im,node->left);
    render_recur(im,node->right);
    return ;
}

   

void twoDtree::prune(double pct, int tol){
	prune_recur(pct, tol, root);
}

void twoDtree::prune_recur(double pct, int tol, Node* & root){
	double num_leafs = ((root->lowRight.first - (root->upLeft.first) + 1 )) * ((root->lowRight.second - (root->upLeft.second) + 1));
	  if((root->left == NULL) && (root->right == NULL)){
	  	return;
	  }

      if  ((prune_count(pct, tol, root, root)/num_leafs) >= pct){
      	del(root->left);
      	root->left = NULL;
      	del(root->right);
      	root->right = NULL;
      	return;
      }

      else
      	prune_recur(pct,tol,root->left);
        prune_recur(pct,tol,root->right);
 }


long twoDtree::prune_count(double pct, int tol, Node* & root, Node* & child){
    long count = 0;
	if ((child->left == NULL) && (child->right == NULL)){
		long avg_r = (((root->avg.r) - (child->avg.r)) * ((root->avg.r) - (child->avg.r)));
		long avg_b = (((root->avg.b) - (child->avg.b)) * ((root->avg.b) - (child->avg.b)));
		long avg_g = (((root->avg.g) - (child->avg.g)) * ((root->avg.g) - (child->avg.g)));

		long distance = avg_r + avg_b + avg_g;	
		if (distance <= tol)
			return 1;
	}

	else {
		count += prune_count(pct,tol,root,child->left);
		count += prune_count(pct,tol,root,child->right);
			
	}
	return count;
	}


void twoDtree::clear() {
	del(root);
}


void twoDtree::del(Node*& n){
if (n == NULL){
 	return;
 }
	
  del(n->left);
  del(n->right);
  delete(n);
}
      
	
void twoDtree::copy(const twoDtree & orig){
 	height = orig.height;
 	width = orig.width;
 	root = copytree(orig.root);
 	
}

twoDtree::Node * twoDtree::copytree(const Node* curr){
	if (curr == NULL){
    	return NULL;
	}
 	Node* n = new Node(curr->upLeft, curr->lowRight, curr->avg);

     n->left = copytree(curr->left);
     n->right = copytree(curr->right);
   return n;
}
     