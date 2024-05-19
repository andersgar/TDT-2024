#include "Tile.h"

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
											   {Cell::open, ""},
											   {Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : Button({pos.x, pos.y}, 1.5 * size, size, "")
{
	setButtonColor(TDT4102::Color::silver);
}

void Tile::open()
{
	if (state == Cell::open || state == Cell::flagged)
	{ // Already flagged or opened -> Do nothing
		return;
	}
	else
	{ // Opening
		setButtonColor(TDT4102::Color::white);
		state = Cell::open;
		if (isMine)
		{
			set_label("X");
			set_label_color(TDT4102::Color::red);
		}
	}
}

void Tile::flag()
{
	if (state == Cell::flagged)
	{ // Unflag
		state = Cell::closed;
	}
	else
	{ // Flag
		state = Cell::flagged;
		set_label_color(TDT4102::Color::black);
	}

	set_label(cellToSymbol.at(state));
}

bool Tile::checkIfMine() const { return isMine; }

void Tile::setMine() { isMine = true; }

void Tile::setAdjMines(int n)
{
	set_label(std::to_string(n));
	set_label_color(minesToColor.at(n));
}

void Tile::resetTile()
{
	state = Cell::closed;
	isMine = false;
	set_label("");
	set_label_color(TDT4102::Color::black);
	setButtonColor(TDT4102::Color::silver);
}