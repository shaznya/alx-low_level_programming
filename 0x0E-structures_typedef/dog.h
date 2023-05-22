#ifndef DOG_H
#define DOG_H
/**
  *struct dog - structure data type
  *@name: name of structure data type
  *@age: age of structure data type
  *@owner: owner of structure data type
  */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
typedef struct dog dog_t;
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
