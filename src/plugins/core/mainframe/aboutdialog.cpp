// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "aboutdialog.h"
#include "common/common.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLatin1String>
#include <QDateTime>

const QString ICON_LOGO_128PX = ":/core/images/unioncode@128.png";

AboutDialog::AboutDialog(QDialog *parent)
    : QDialog(parent)
{
    setupUi();
}

AboutDialog::~AboutDialog()
{

}

void AboutDialog::setupUi()
{
    setWindowTitle(tr("About Deepin Union Code"));

    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(QPixmap(ICON_LOGO_128PX));

    QString buildDateInfo = tr("<br/>Built on %1 %2 in %3<br/>")
            .arg(QLatin1String(__DATE__), QLatin1String(__TIME__), ProcessUtil::localPlatform());

    const QString description = tr(
        "<h3>Deepin Union Code %1</h3>"
        "%2<br/>"
        "Copyright 2019-%3 UnionTech Software Technology Co., Ltd. All rights reserved.<br/>"
        "<br/>")
        .arg(version(),
             buildDateInfo,
             QString::number(QDateTime::currentDateTime().date().year()));

    QLabel *copyRightLabel = new QLabel(description);
    copyRightLabel->setWordWrap(true);
    copyRightLabel->setOpenExternalLinks(true);
    copyRightLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    QHBoxLayout *layoutButtons = new QHBoxLayout();
    QPushButton *closeButton = new QPushButton(QPushButton::tr("Close"));
    connect(closeButton , &QPushButton::clicked, this, &QDialog::reject);
    layoutButtons->addStretch();
    layoutButtons->addWidget(closeButton);

    auto layout = new QGridLayout(this);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(logoLabel , 1, 0, 1, 1);
    layout->addWidget(copyRightLabel, 0, 4, 4, 5);
    layout->addLayout(layoutButtons, 4, 4, 1, 5);
}
