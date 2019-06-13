import { postPosition } from '../api/index';

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
      <div class="rectangle" id="rectangle"></div>`
  }

  constructor() {
    super();
  }

  connectedCallback() {
    this.attachShadow({
      mode: 'open'
    })
  this.shadowRoot.innerHTML = AppRectangle.template;
    this.rectangle = this.shadowRoot.querySelector("#rectangle");
    this.rectangle.addEventListener('click', e => {
      postPosition(1, 2);
    })
  }
}
