/*
 * OptieScherm.cpp
 *
 *  Created on: 3 mrt. 2012
 *      Author: acer
 */

#include "OptieScherm.hpp"

OptieScherm::OptieScherm( Screen* parent )
{
	//sla parent scherm op (FotoScherm) om de show() te kunnen aanroepen, zodat dit optiescherm weer gesloten wordt
	this->parent = parent;
	achtergrondKleur = 1; // 1 rood 2 groen 3 blauw

	//bepaal grootte van het scherm


	//standaard font en grafisch uiterlijk (uit de resource file res.lst)
	Font* font = new MAUI::Font(RES_FONT);

	WidgetSkin* skin = new WidgetSkin( RES_SELECTED, RES_UNSELECTED, 16, 32, 16, 32, false, false );

	//maak een label die andere widgets straks bevat, en een achtergrondkleur heeft
	label = new Label(0,0,0,0, NULL);

	//stel achtergrondkleur in
	label->setBackgroundColor(0xFFFFFF);


	this->setMain(this->label);

	//maak rode knop
	this->roodLabel = new Label(10, 20, 50, 30, label,"Rood", 0, font);
	roodLabel->setSkin( skin );

	this->kleurLabels.add( roodLabel );	//voeg toe aan vector


	//maak groene knop
	this->groenLabel = new Label(70, 20, 50, 30, label, "Groen", 0, font);
	this->groenLabel->setSkin(skin);
	this->kleurLabels.add(groenLabel);

	//maak blauwe knop
	this->blauwLabel = new Label(160, 20, 50, 30, label,"Blauw", 0, font);
	this->blauwLabel->setSkin(skin);
	this->kleurLabels.add(blauwLabel);

	this->toepasKnop = new Label(50, 270, 80, 30, label,"Pas Toe", 0, font);
	this->toepasKnop->setSkin(skin);

	//stel grootte plaatje in m.b.v. editbox
	//stel naam plaatje in m.b.v. editbox
	this->editBoxGrootte = new EditBox(50, 100, 100, 50, label, "100", 0x000000, font, true, false,3,EditBox::IM_NUMBERS);


	this->editBoxText = new EditBox(50, 220, 100, 50 , label, "Text", 0x000000, font, true, false,10 ,EditBox::IM_QWERTY );


}

OptieScherm::~OptieScherm()
{
	//verwijder objecten van deze klasse
}


//geef ingestelde achtergrondkleur terug
int OptieScherm::getAchtergrondOptie()
{
	//return achtergrond kleur
	return this->achtergrondKleur;

}

int OptieScherm::grootte()
{
	int grootte  = atoi ( this->editBoxGrootte->getCaption().c_str() );
	return grootte;

}


//geef ingestelde imagetekst van de editbox terug
const BasicString<char> OptieScherm::getImagetekst()
{
	//verander editBox naar jouw editboxs
	return this->editBoxText->getCaption(); //caption is de text in een editbox
}


void OptieScherm::keyPressEvent(int keyCode, int nativeCode)
{
	//laat bij MAK_FIRE knop indrukken de parent (FotoScherm dus) weer zien
	if(MAK_FIRE == keyCode)
	{
		this->parent->show();
	}
}

void OptieScherm::pointerPressEvent(MAPoint2d p)
{
	Point point;
	point.x = p.x;
	point.y = p.y;
	//doorloop alle kleurlabels om selectie in te stellen

	if(this->roodLabel->contains(point))
	{
		this->achtergrondKleur = 1;
		this->roodLabel->setSelected(true);
	}
	else
	{
		this->roodLabel->setSelected(false);
	}

	if(this->groenLabel->contains(point))
	{
		this->achtergrondKleur = 2;
		this->groenLabel->setSelected(true);
	}
	else
	{
		this->groenLabel->setSelected(false);
	}

	if(this->blauwLabel->contains(point))
	{
		this->achtergrondKleur = 3;
		this->blauwLabel->setSelected(true);
	}
	else
	{
		this->blauwLabel->setSelected(false);
	}

	if(this->toepasKnop->contains(point))
	{
		this->parent->show();
	}



	//behandel de editbox bij selecteren (touch), verander de editBox naar je eigen editbox(en)
	if(editBoxGrootte->contains(point))
	{
		editBoxText->deactivate();
		editBoxGrootte->setText("");
		editBoxGrootte->activate();

	}

	if(editBoxText->contains(point))
	{
		editBoxGrootte->deactivate();
		editBoxText->setText("");
		editBoxText->activate();
	}

}

