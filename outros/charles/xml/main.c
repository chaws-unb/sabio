#include <simpleXML.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("***** Starting *****\n");

	// Create
	printf("Creating xml object...\n");
	xmlNode * xml = newSimpleXml("myTest3");


	// Add attribute
	printf("Adding xml object some attributes...");
	if(!addAttribute(xml, "attr1", "val1"))
		printf("attr1 Done!\n");
	else
		printf("Ops, something wrong happened!\n");

	if(!addAttribute(xml, "attr2", "val2"))
		printf("attr1 Done!\n");
	else
		printf("Ops, something wrong happened!\n");


	// Create children
	printf("Creating xml object a child node...");
	xmlNode * child1 = createNode(xml, "child1");
	if(child1)
		printf("child1 Done!\n");
	else
		printf("Ops, something wrong happened!\n");

	// Child1's attribute
	printf("Adding xml object some attributes to child1...");
	if(!addAttribute(child1, "attr1", "val1"))
		printf("attr1 Done!\n");
	else
		printf("Ops, something wrong happened!\n");


	// Create children's child
	printf("Creating xml object a child1's node ...");
	xmlNode * child2 = createNode(child1, "child2");
	if(child2)
		printf("child2 Done!\n");
	else
		printf("Ops, something wrong happened!\n");

	// Child2's attribute
	printf("Adding xml object some attributes to child2...");
	if(!addAttribute(child2, "attr1", "val1"))
		printf("attr1 Done!\n");
	else
		printf("Ops, something wrong happened!\n");

	// Create second child of xml
	printf("Creating xml object a second child node...");
	xmlNode * child3 = createNode(xml, "child3");
	if(child3)
		printf("child3 Done!\n");
	else
		printf("Ops, something wrong happened!\n");


	// Save to file
	printf("Saving xml object into myTest.xml...");
	if(!saveToFile(xml, "myTest.xml"))
		printf("Done!\n");
	else
		printf("Ops, something wrong happened!\n");


	// Free! we are free!
	printf("Destroying xml object...\n");
	destroyNode(xml);

	printf("***** Finishing *****\n");
	return 0;
}
