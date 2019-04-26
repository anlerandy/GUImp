#include "vectors.h"

/*
t_vec2			init_v2(double x, double y);						ok
t_vec3			init_v3(double x, double y, double z);				ok
t_vec			init_v(int size);
t_mat			init_mat(int w, int h);

void			free_v(t_vec *a);
void			free_mat(t_mat *a);

t_vec2			mult_v2(t_vec2 a, t_vec2 b);						ok
t_vec3			mult_v3(t_vec3 a, t_vec3 b);						ok
t_mat			mult_mat(t_mat a, t_mat b);
t_vec			mult_v(t_vec a, t_vec b);

t_vec3			mult_mat_v3(t_vec3 a, t_mat b);
t_vec2			mult_mat_v2(t_vec2 a, t_mat b);
t_vec			mult_mat_v(t_vec a, t_mat b);

t_vec2			add_v2(t_vec2 a, t_vec2 b);							ok
t_vec3			add_v3(t_vec3 a, t_vec3 b);							ok
t_mat			add_mat(t_mat a, t_mat b);
t_vec			add_v(t_vec a, t_vec b);

t_vec2			sub_v2(t_vec2 a, t_vec2 b);							ok
t_vec3			sub_v3(t_vec3 a, t_vec3 b);							ok
t_mat			sub_mat(t_mat a, t_mat b);
t_vec			sub_v(t_vec a, t_vec b);

inline t_vec2	scale_v2(double a, t_vec2 b)						ok
inline t_vec3	scale_v3(double a, t_vec3 b)						ok

t_vec2			normalize_v2(t_vec2 a)								ok
inline double 	norme_v2(t_vec2 a)									ok
t_vec3			normalize_v3(t_vec3 a)								ok
inline double 	norme_v3(t_vec3 a)									ok

t_vec2			rot_vec2(t_vec2 v, double theta);					ok
t_vec3			rot_vec3(t_vec3 v, double theta, t_vec3 axis);		ok
t_vec3			rot_vec3_x(t_vec3 v, double theta);					ok
t_vec3			rot_vec3_y(t_vec3 v, double theta);					ok
t_vec3			rot_vec3_z(t_vec3 v, double theta);					ok

t_mat			init_id_mat(int w);
t_mat			rot_mat(t_vec3 v, double theta);

void			print_v2(t_vec2 a);									ok
void			print_v3(t_vec3 a);									ok

*/

int main()
{
	t_vec2 a2;
	t_vec2 b2;


	a2 = init_v2(0.45, 10);

	print_v2(a2);
	printf("norme : %lf\n", norme_v2(a2));
	a2 = scale_v2(10, a2);
	print_v2(a2);
	a2 = normalize_v2(a2);
	printf("normalized : ");
	print_v2(a2);
	printf("norme : %lf\n", norme_v2(a2));

	b2 = init_v2(0.2, 12);
	print_v2(a2);
	print_v2(b2);
	printf("add : ");
	print_v2(add_v2(a2, b2));
	printf("sub : ");
	print_v2(sub_v2(a2, b2));	
	printf("mult : ");
	print_v2(mult_v2(a2, b2));


	printf("\n");
	printf("\n");

	t_vec3 a3;
	t_vec3 b3;

	a3 = init_v3(0.45, 10, 29);
	print_v3(a3);
	printf("norme : %lf\n", norme_v3(a3));
	a3 = scale_v3(10, a3);
	print_v3(a3);
	a3 = normalize_v3(a3);
	printf("normalized : ");
	print_v3(a3);
	printf("norme : %lf\n", norme_v3(a3));

	b3 = init_v3(0.3, 13, -29);
	print_v3(a3);
	print_v3(b3);
	printf("add : ");
	print_v3(add_v3(a3, b3));
	printf("sub : ");
	print_v3(sub_v3(a3, b3));
	printf("mult : ");
	print_v3(mult_v3(a3, b3));

	a3 = init_v3(1, 1, 1);
	b3 = normalize_v3(init_v3(1, 1, -1));
	print_v3(rot_vec3_x(a3, M_PI));
	print_v3(rot_vec3_y(a3, M_PI));
	print_v3(rot_vec3_z(a3, M_PI));
	print_v3(rot_vec3_x(a3, M_PI / 3.0));
	print_v3(rot_vec3_y(a3, M_PI / 3.0));
	print_v3(rot_vec3_z(a3, M_PI / 3.0));
	print_v3(rot_vec3(a3, M_PI, b3));

	return (42);
}