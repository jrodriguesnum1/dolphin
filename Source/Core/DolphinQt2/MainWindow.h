// Copyright 2015 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QToolBar>

#include "DolphinQt2/MenuBar.h"
#include "DolphinQt2/RenderWidget.h"
#include "DolphinQt2/ToolBar.h"
#include "DolphinQt2/GameList/GameList.h"

class PathDialog;

class MainWindow final : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow();
	~MainWindow();

signals:
	void EmulationStarted();
	void EmulationPaused();
	void EmulationStopped();

private slots:
	void Open();
	void Play();
	void Pause();

	// May ask for confirmation. Returns whether or not it actually stopped.
	bool Stop();
	void ForceStop();

	void FullScreen();
	void ScreenShot();

private:
	void CreateComponents();

	void ConnectGameList();
	void ConnectMenuBar();
	void ConnectRenderWidget();
	void ConnectStack();
	void ConnectToolBar();
	void ConnectPathsDialog();

	void StartGame(const QString& path);
	void ShowRenderWidget();
	void HideRenderWidget();

	void ShowPathsDialog();
	void ShowAboutDialog();

	QStackedWidget* m_stack;
	ToolBar* m_tool_bar;
	MenuBar* m_menu_bar;
	GameList* m_game_list;
	RenderWidget* m_render_widget;
	bool m_rendering_to_main;

	PathDialog* m_paths_dialog;
};
