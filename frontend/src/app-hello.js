export default class AppHello extends HTMLElement {
  static get template() {
    return `<p>hello</p>`
  }

  constructor() {
    super();
  }

  connectedCallback() {
    this.attachShadow({
      mode: 'open'
    }).innerHTML = AppHello.template;
  }
}
