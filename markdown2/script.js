// import 'CodeMirror/mode/xml/xml';
// import 'CodeMirror/addon/edit/matchbrackets';
// import CodeMirror from 'CodeMirror';
// import marked     from 'marked';

class App {
  constructor(options) {
    this.init();
    this.addEventListeners();
  }

  init() {
    const input = this.input = CodeMirror.fromTextArea(document.querySelector('.js-input'), {
      lineNumbers: true,
      matchBrackets: true,
      mode: 'text/x-markdown',
      theme: 'material' });


    const output = this.output = CodeMirror.fromTextArea(document.querySelector('.js-output'), {
      lineNumbers: true,
      matchBrackets: true,
      mode: 'text/html',
      theme: 'material',
      readOnly: true });


    this.preview = document.querySelector('.js-preview');

    output.getWrapperElement().classList.add('CodeMirror-readonly');

	$.ajax({
		url : "abrirTxt2.txt",
		dataType: "text",
		success : function (data) {
			//console.log(data);
			input.setValue(data);
		}
	});

	//input.setValue("234");

    this.compile(input.getValue());
  }

  compile(source) {
    const previewDocument = this.preview.contentDocument;
    const output = marked(source);

    previewDocument.open();
    previewDocument.write(output);
    previewDocument.close();

    this.output.setValue(output);
  }

  addEventListeners() {
    const { input } = this;
    let delay;

    input.on('change', () => {
      clearTimeout(delay);
      delay = setTimeout(() => this.compile(input.getValue()), 300);
    });
  }}



new App();