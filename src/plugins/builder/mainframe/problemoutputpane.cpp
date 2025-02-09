// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "problemoutputpane.h"
#include "tasks/taskmanager.h"
#include "services/builder/task.h"


#include "common/common.h"

#include <QVBoxLayout>

ProblemOutputPane::ProblemOutputPane(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(TaskManager::instance()->getView());
    setLayout(layout);
}

ProblemOutputPane::~ProblemOutputPane()
{

}

void ProblemOutputPane::clearContents()
{
    TaskManager::instance()->clearTasks();
}

void ProblemOutputPane::addTask(const Task &task, int linkedOutputLines, int skipLines)
{
    TaskManager::instance()->slotAddTask(task, linkedOutputLines, skipLines);
}


void ProblemOutputPane::contextMenuEvent(QContextMenuEvent * event)
{
    if (nullptr == menu) {
        menu = new QMenu(this);
        menu->setParent(this);
        menu->addActions(actionFactory());
    }

    menu->move(event->globalX(), event->globalY());
    menu->show();
}

QList<QAction*> ProblemOutputPane::actionFactory()
{
    QList<QAction*> list;
    auto action = new QAction(this);
    action->setText(tr("Clear"));
    connect(action, &QAction::triggered, [this](){
        clearContents();
    });
    list.append(action);
    return list;
}


