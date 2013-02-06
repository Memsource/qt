/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qpatternistlocale_p.h"

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    QString escape(const QString &input)
    {
        QString rich;
        rich.reserve(int(input.length() * 1.1));

        for(int i = 0; i < input.length(); ++i)
        {
            switch(input.at(i).unicode())
            {
                case '<':
                {
                    rich += QLatin1String("&lt;");
                    break;
                }
                case '>':
                {
                    rich += QLatin1String("&gt;");
                    break;
                }
                case '&':
                {
                    rich += QLatin1String("&amp;");
                    break;
                }
                case '"':
                {
                    rich += QLatin1String("&quot;");
                    break;
                }
                case '\'':
                {
                    rich += QLatin1String("&apos;");
                    break;
                }
                case '«':
                {
                    rich += QLatin1String("&laquo;");
                    break;
                }
                case '»':
                {
                    rich += QLatin1String("&raquo;");
                    break;
                }
                case 0x2018:
                {
                    rich += QLatin1String("&lsquo;");
                    break;
                }
                case 0x2019:
                {
                    rich += QLatin1String("&rsquo;");
                    break;
                }
                case 0x201A:
                {
                    rich += QLatin1String("&sbquo;");
                    break;
                }
                case 0x201B:
                {
                    rich += QLatin1String("&#8219;");
                    break;
                }
                case 0x201C:
                {
                    rich += QLatin1String("&ldquo;");
                    break;
                }
                case 0x201D:
                {
                    rich += QLatin1String("&rdquo;");
                    break;
                }
                case 0x201E:
                {
                    rich += QLatin1String("&bdquo;");
                    break;
                }
                case 0x201F:
                {
                    rich += QLatin1String("&#8223;");
                    break;
                }
                case 0x2039:
                {
                    rich += QLatin1String("&lsaquo;");
                    break;
                }
                case 0x203A:
                {
                    rich += QLatin1String("&lsaquo;");
                    break;
                }
                // Quotation marks in Chinese, Japanese, and Korean (CJK)
                case 0x300C:
                {
                    rich += QLatin1String("&#12300;");
                    break;
                }
                case 0x300D:
                {
                    rich += QLatin1String("&#12301;");
                    break;
                }
                case 0x300E:
                {
                    rich += QLatin1String("&#12302;");
                    break;
                }
                case 0x300F:
                {
                    rich += QLatin1String("&#12303;");
                    break;
                }
                case 0x301D:
                {
                    rich += QLatin1String("&#12317;");
                    break;
                }
                case 0x301E:
                {
                    rich += QLatin1String("&#12318;");
                    break;
                }
                case 0x301F:
                {
                    rich += QLatin1String("&#12319;");
                    break;
                }
                // Alternate encodings
                case 0xFE41:
                {
                    rich += QLatin1String("&#65089;");
                    break;
                }
                case 0xFE42:
                {
                    rich += QLatin1String("&#65090;");
                    break;
                }
                case 0xFE43:
                {
                    rich += QLatin1String("&#65091;");
                    break;
                }
                case 0xFE44:
                {
                    rich += QLatin1String("&#65092;");
                    break;
                }
                case 0xFF02:
                {
                    rich += QLatin1String("&#65282;");
                    break;
                }
                case 0xFF07:
                {
                    rich += QLatin1String("&#65287;");
                    break;
                }
                case 0xFF62:
                {
                    rich += QLatin1String("&#65378;");
                    break;
                }
                case 0xFF63:
                {
                    rich += QLatin1String("&#65379;");
                    break;
                }
                default:
                    rich += input.at(i);
            }
        }

        return rich;
    }
}

QT_END_NAMESPACE
