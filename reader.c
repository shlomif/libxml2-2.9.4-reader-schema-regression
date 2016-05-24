/*
 * I compile this program using:
 *
 * gcc -I /home/shlomif/apps/xml/libxml2/include/libxml2/ -L /home/shlomif/apps/xml/libxml2/lib reader.c -lxml2
 *
 * With libxml2-2.9.4 it emits some validity errors to stderr.
 *
 * With libxml2-2.9.3 everything is  fine.
 *
 * License is the MIT license - Copyright by Shlomi Fish, 2016.
 *
 * Originally reported here - https://rt.cpan.org/Ticket/Display.html?id=114638
 * */
#include <stdio.h>
#include <libxml/xmlreader.h>
int main()
{
    xmlTextReaderPtr reader = xmlReaderForFile("test/schema/demo.xml", "utf8", 0);

    xmlTextReaderSchemaValidate(reader, "test/schema/schema.xsd");
    int ret;

    while (1)
    {
        ret = xmlTextReaderRead(reader);
        printf("ret=%d\n", ret);
    }

    return 0;
}
