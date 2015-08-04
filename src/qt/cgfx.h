// GB Enhanced+ Copyright Daniel Baxter 2015
// Licensed under the GPLv2
// See LICENSE.txt for full license text

// File : cgfx.h
// Date : July 25, 2015
// Description : Custom graphics settings
//
// Dialog for various custom graphics options

#ifndef CGFX_GBE_QT
#define CGFX_GBE_QT

#include <vector>

#include <SDL/SDL.h>

#include <QtGui>

class gbe_cgfx : public QDialog
{
	Q_OBJECT
	
	public:
	gbe_cgfx(QWidget *parent = 0);

	void update_obj_window(int rows, int count);
	void update_bg_window(int rows, int count);

	QTabWidget* tabs;
	QDialogButtonBox* tabs_button;

	//OBJ tab widgets
	std::vector<QImage> cgfx_obj;
	std::vector<QPushButton*> obj_button;

	//BG tab widgets
	std::vector<QImage> cgfx_bg;
	std::vector<QPushButton*> bg_button;

	bool pause;

	protected:
	void closeEvent(QCloseEvent* event);

	private:
	QWidget* obj_set;
	QWidget* bg_set;

	QGridLayout* obj_layout;
	QGridLayout* bg_layout;

	QSignalMapper* obj_signal;
	QSignalMapper* bg_signal;

	void setup_obj_window(int rows, int count);
	QImage grab_obj_data(int obj_index);

	void setup_bg_window(int rows, int count);
	QImage grab_bg_data(int bg_index);

	private slots:
	void close_cgfx();
	void dump_obj(int obj_index);
	void dump_bg(int bg_index);
};

#endif //CGFX_GBE_QT 
