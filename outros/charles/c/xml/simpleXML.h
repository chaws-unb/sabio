#ifndef SIMPLEXML
#define SIMPLEXML
#include <stdlib.h>

/**
 *	Define an attribute of a node <ex attr="val"> 
 */
typedef struct _nodeAttribute
{
	char * name;
	char * value;
	struct _nodeAttribute * next; // lazy way of a simple linked list
} nodeAttribute;

/**
 *	Define a xml node <ex> <child></child> </ex>
 */
typedef struct _xmlNode
{
	char * name;
	/* char * content; next version*/
	struct _xmlNode * parent;
	struct _xmlNode * children;
	struct _xmlNode * next; // lazy way of a simple linked list
	nodeAttribute * attributes;
} xmlNode;

/**
 *	Create a new xml object
 *	rootName = name of the root xml node
 *	return xmlNode * root element
 */
xmlNode * newSimpleXml(const char * rootName);

/**	
 *	Member function of xmlNode
 *	name = attribute name
 *	value = attribute value
 */
int addAttribute(xmlNode * node, const char * name, char * value);

/**
 *	Create a children node
 *	parent = parent node to which children will be created
 *	nodeName = as it says
 *	return xmlNode, the new node
 */
xmlNode * createNode(xmlNode * parent, const char * nodeName);

/**
 *	Destroy the node and its children
 */
void destroyNode(xmlNode * node);

/**
 *	Output the xml file on a filename
 */
int saveToFile(const xmlNode * node, const char * filename);

#endif
