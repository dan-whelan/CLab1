#include "Relation.h"

#include "trees.h"

extern Rel likes;
extern Rel student;
extern Rel lecturer;
extern Rel subject;
extern Rel unicorn;
extern Rel kissed;
extern Rel froze;

bool compute_s_value(Tree *t);
Thing compute_np_value(Tree *t);
Rel compute_vp_value(Tree *t);
Rel compute_n_value(Tree *t);
Rel compute_tv_value(Tree *t);
Rel flip(Rel r);
bool match(Tree *t, Rule r);
