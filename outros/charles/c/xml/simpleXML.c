#include "simpleXML.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef new
	#define new(type) ((type *)malloc(sizeof(type)))
#endif

xmlNode * newSimpleXml(const char * rootName)
{
	// This will be the only node with a null parent
	return createNode(NULL, rootName);
}

int addAttribute(xmlNode * node, const char * name, char * value)
{
	if(!node)
		return -1;

	nodeAttribute * attribute = new(nodeAttribute);
	if(!attribute)
		return -2;

	attribute->name  = strdup(name);
	attribute->value = value;
	attribute->next  = NULL;

	// Check if there is any attribute attached to this node
	if(!node->attributes)
	{
		node->attributes = attribute;
		return 0;
	}

	// Look for the last attribute element, then attach to last's next position
	nodeAttribute * tmp   = node->attributes, 
				  * last  = node->attributes;
	while(tmp->next) last = tmp;
	last->next 			  = attribute;

	return 0;
}

xmlNode * createNode(xmlNode * parent, const char * nodeName)
{
	xmlNode * node = new(xmlNode);
	if(!node)
		return NULL;

	// Copy only the first 127 chars
	unsigned char length = (strlen(nodeName) > 127 ? 127 : strlen(nodeName));
	char * tmp = (char *)malloc(sizeof(char) * length);
	// TODO: VALIDATE NODENAME
	strncpy(tmp, nodeName, length);

	node->name 		 = tmp;
	node->children 	 = NULL;
	node->attributes = NULL;
	node->next 		 = NULL;
	node->parent 	 = parent;

	// Special treatment if parent exists
	if(parent)
	{
		// Check if this there's more kids around here!
		if(!parent->children)
			parent->children = node;
		else
		{
			// Otherwise go to last child and attach it
			xmlNode * tmp   = parent->children, 
					* last  = parent->children;
			while(tmp->next) last = tmp;
			last->next 			  = node;
		}
	}

	return node;
}

void destroyNode(xmlNode * node)
{
	if(!node)
		return;

	free(node->name);

	// free attributes
	if(node->attributes)
	{
		nodeAttribute * tmp = node->attributes;
		do
		{
			tmp = tmp->next;
			free(node->attributes);
			node->attributes = tmp;
		}while(tmp);
	}

	// free attributes
	if(node->children)
	{
		xmlNode * tmp = node->children;
		do
		{
			tmp = tmp->next;
			destroyNode(node->children);
			free(node->children);
			node->children = tmp;
		}while(tmp);
	}
}

int saveToFile(const xmlNode * node, const char * filename)
{
	if(!node)
		return -1;

	// TODO: VALIDATE FILENAME
	static FILE * file = NULL;
	if(!file){
		file = fopen(filename, "w+");
		if(!file)
			return -2;
	}

	// XML header file
	static char headerIncluded = 0;
	if(!headerIncluded)
	{
		fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
		headerIncluded = 1;
	}

	// Pequena gambiarra pra chamar essa funcao recursivamente hehe
	static int level = 0;

	int i;
	i = 0;
	while(i++ < level) fprintf(file, "\t");

	// Node name (it's open due to attributes)
	fprintf(file, "<%s", node->name);

	// Output attributes
	if(node->attributes)
	{
		nodeAttribute * tmp = node->attributes;
		do
		{
			fprintf(file, " %s=\"%s\"", tmp->name, tmp->value);
			tmp = tmp->next;
		}while(tmp);
	}

	// Close opening node
	fprintf(file, ">\n");

	// Output children
	int rc = 0;
	if(node->children)
	{
		xmlNode * tmp = node->children;
		do
		{
			level++;
			if((rc = saveToFile(tmp, filename)))
				return rc;
			level--;
			tmp = tmp->next;
		}while(tmp);
	}

	// Close node tag
	i = 0; 
	while(i++ < level) fprintf(file, "\t");
	fprintf(file, "</%s>\n", node->name);

	// Close the file
	if(level == 0)
		fclose(file);

	return 0;
}
