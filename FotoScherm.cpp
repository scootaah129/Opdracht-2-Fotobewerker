/*
 * FotoScherm.cpp
 *
 *  Created on: 3 mrt. 2012
 *      Author: acer
 */

#include "FotoScherm.hpp"

FotoScherm::FotoScherm()
{
	//het optiescherm
	this->optieScherm = new OptieScherm( this );


	//bepaal grootte van het scherm

	//standaard font en grafisch uiterlijk (uit de resource file res.lst)
	Font* font = new MAUI::Font(RES_FONT);
	WidgetSkin* skin = new WidgetSkin( RES_SELECTED, RES_UNSELECTED, 16, 32, 16, 32, false, false );

	//maak een label die andere widgets straks bevat, en een achtergrondkleur heeft
	achtergrondLabel = new Label(0,0,0,0, NULL);
	achtergrondLabel->setBackgroundColor(0xFFFFFF);

	//maak een plaatje (laden uit de resource file res.lst) en voeg label als parent toe
	this->grootte = 100;
	this->image = new Image(10, 10, grootte, grootte, achtergrondLabel, true, true, RES_IMAGE);

	//maak tekst bij het plaatje met een label
	imageTekst = new Label(50,170,100,30, achtergrondLabel, "Tekst", 0, font);

	//stel dit scherm in als het main scherm, met achtergrondlabel als de basis widget
	this->setMain( this->achtergrondLabel );

}


FotoScherm::~FotoScherm()
{

}


//show() override de show() van de super klasse (Screen), omdat we bij showen eerst opties willen ophalen
void FotoScherm::show()
{
	//roep de show() van de superklasse (Screen) aan
	this->Screen::show();



	//haal informatie achtergrondkleur op van optiescherm

	if(this->optieScherm->getAchtergrondOptie() == 1)
	{
		this->achtergrondLabel->setBackgroundColor(0xFF0000);
	}
	if(this->optieScherm->getAchtergrondOptie() == 2)
	{
		this->achtergrondLabel->setBackgroundColor(0x00FF00);
	}
	if(this->optieScherm->getAchtergrondOptie() == 3)
	{
		this->achtergrondLabel->setBackgroundColor(0x0000FF);
	}

	//haal informatie imagetekst op van optiescherm
	this->imageTekst->setCaption( this->optieScherm->getImagetekst() );

	this->image->setWidth(this->optieScherm->grootte());
	this->image->setHeight(this->optieScherm->grootte());
	this->image->setPosition(10,10);

}


//afvangen invoer
void FotoScherm::keyPressEvent(int keyCode, int nativeCode)
{
//	//bij indrukken van de MAK_FIRE toets, laat optiescherm zien
	if(MAK_FIRE == keyCode)
	{

		this->optieScherm->show();

	}
}

void FotoScherm::pointerPressEvent(MAPoint2d point)
{
	//bij touch, laat optiescherm zien
	this->optieScherm->show();
}


