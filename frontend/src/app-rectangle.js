export default class AppRectangle extends HTMLElement {
  static get template() {
    return `
      <style>
        .rectangle {
          width: 100px;
          height: 100px;
          background-color: red;
        }
      </style>
      <div class="rectangle"></div>`
  }

  constructor() {
    super();
  }

  connectedCallback() {
    this.attachShadow({
      mode: 'open'
    }).innerHTML = AppRectangle.template;
  }
}
