#ifndef MEMORYTEXTEDITOR_H
#define MEMORYTEXTEDITOR_H

#include <std/mask.h>
#include <QPlainTextEdit>
#include "syntax.h"

class QSyntaxHighlighter;

namespace aske {

class TextEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    //! TextEditor type
    class Type {
    public:
        enum t {
            No   = 0,      //! No content

            Text = 1 << 0, //! Common editor. No lines count, readable font
            Code = 1 << 1, //! Code editor. Lines count, monospaced font
            Hex  = 1 << 2, //! Hex viewer
        };
        static constexpr int count = 3;
        using mask = aske::mask<>; //! Type bitmask
    };

    explicit TextEditor(QWidget *parent = 0);
    explicit TextEditor(Type::mask types = Type::Text, QWidget *parent = 0);
    void setTypes(Type::mask types);
    void switchToType(Type::t types);
    void openFile(const QString &m_fileName);
    void saveFile(const QString &m_fileName);
    void saveFile();
    Type::mask types() { return m_allowedTypes; } //! Types of text editor
    Type::t currentType() { return m_currentType; } //! Current content type

public slots:
    void onFileRenamed(const QString &fileName);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateLook();

    class LineNumberArea : public QWidget
    {
    public:
        LineNumberArea(TextEditor *editor)
            : QWidget(editor)
        {
            textEditor = editor;
        }

        QSize sizeHint() const override {
            return QSize(textEditor->lineNumberAreaWidth(), 0);
        }

    protected:
        void paintEvent(QPaintEvent *event) override {
            textEditor->lineNumberAreaPaintEvent(event);
        }

    private:
        TextEditor *textEditor;
    };

    friend class LineNumberArea;
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

    void applyHighlighter();
    void applyHighlighter(TextEditorPrivate::Syntax::t syntax);
    void deleteHighlighter();

    LineNumberArea m_lineNumberArea;
    QString m_fileName;

    Type::mask m_allowedTypes {Type::Text | Type::Hex}; //! Types allowed by TextEditor
    Type::t m_currentType {Type::No}; //! Current TextEditorType
    Type::t m_fileType {Type::No}; //! Type of a current file

    QSyntaxHighlighter *m_highlighter {nullptr};
};

} // namespace aske

#endif // MEMORYTEXTEDITOR_H
