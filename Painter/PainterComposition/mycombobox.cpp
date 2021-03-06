#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent) : QComboBox(parent)
{
    addItem("CompositionMode_SourceOver",0);
    addItem("CompositionMode_DestinationOver",1);
    addItem("CompositionMode_Clear",2);
    addItem("CompositionMode_Source",3);
    addItem("CompositionMode_Destination",4);
    addItem("CompositionMode_SourceIn",5);
    addItem("CompositionMode_DestinationIn",6);
    addItem("CompositionMode_SourceOut",7);
    addItem("CompositionMode_DestinationOut",8);
    addItem("CompositionMode_SourceAtop",9);
    addItem("CompositionMode_DestinationAtop",10);
    addItem("CompositionMode_Xor",11);
    addItem("CompositionMode_Plus",12);
    addItem("CompositionMode_Multiply",13);
    addItem("CompositionMode_Screen",14);
    addItem("CompositionMode_Overlay",15);
    addItem("CompositionMode_Darken",16);
    addItem("CompositionMode_Lighten",17);
    addItem("CompositionMode_ColorDodge",18);
    addItem("CompositionMode_ColorBurn",19);
    addItem("CompositionMode_HardLight",20);
    addItem("CompositionMode_SoftLight",21);
    addItem("CompositionMode_Difference",22);
    addItem("CompositionMode_Exclusion",23);
    addItem("RasterOp_SourceOrDestination",24);
    addItem("RasterOp_SourceAndDestination",25);
    addItem("RasterOp_SourceXorDestination",26);
    addItem("RasterOp_NotSourceAndNotDestination",27);
    addItem("RasterOp_NotSourceOrNotDestination",28);
    addItem("RasterOp_NotSourceXorDestination",29);
    addItem("RasterOp_NotSource",30);
    addItem("RasterOp_NotSourceAndDestination",31);
    addItem("RasterOp_SourceAndNotDestination",32);
    addItem("RasterOp_NotSourceOrDestination",33);
    addItem("RasterOp_SourceOrNotDestination",34);
    addItem("RasterOp_ClearDestination",35);
    addItem("RasterOp_SetDestination",36);
    addItem("RasterOp_NotDestination",37);
}
