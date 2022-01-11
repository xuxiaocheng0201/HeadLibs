#ifndef HLS_POLYGON_H
#define HLS_POLYGON_H

#include <math.h>
#include "common/vector.h"

#define POLYGON_ERROR -1

struct polygon_vertex
{
	long long int x;
	long long int y;
	inline void init()
	{
		x=0;
		y=0;
		return;
	}
};

inline double line_length(polygon_vertex a,polygon_vertex b)
{
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}

inline double polygon_circumference(vector<polygon_vertex> polygon)
{
	unsigned int sides=polygon.size();
	if(sides<=1)
		return POLYGON_ERROR;
	if(sides==2)
		return line_length(polygon[0],polygon[1]);
	double circumference=0;
	for(unsigned int i=0;i<sides-1;i++)
		circumference+=line_length(polygon[i],polygon[i+1]);
	return circumference+line_length(polygon[sides-1],polygon[0]);
}

inline double triangle_square(polygon_vertex a,polygon_vertex b,polygon_vertex c)
{
	double ab=line_length(a,b);
	double ac=line_length(a,c);
	double bc=line_length(b,c);
	double p=(ab+ac+bc)/2;
	return sqrt(p*(p-ab)*(p-ac)*(p-bc));
}

inline double polygon_square(vector<polygon_vertex> polygon)
{
	unsigned int sides=polygon.size();
	if(sides<=1)
		return POLYGON_ERROR;
	if(sides==2)
		return line_length(polygon[0],polygon[1]);
	if(sides==3)
		return triangle_square(polygon[0],polygon[1],polygon[2]);
	double square=0;
	for(unsigned int i=1;i<sides-1;i++)
		square+=triangle_square(polygon[0],polygon[i],polygon[i+1]);
	return square;
}

#endif
